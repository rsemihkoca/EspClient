#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_chip_info.h"
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "nvs_flash.h"

#define WIFI_SSID "ZYXEL_C4F1"
#define WIFI_PASS "4KJNF7APJG"

void wifi_init_sta(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    wifi_config_t wifi_config = {
            .sta = {
                    .ssid = WIFI_SSID,
                    .password = WIFI_PASS,
            },
    };

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI("WiFi", "wifi_init_sta finished.");

    ESP_ERROR_CHECK(esp_wifi_connect());
}

void print_chip_info_task(void *pvParameter)
{
    esp_chip_info_t chip_info;
    uint8_t mac[6];

    while (true)
    {
        esp_chip_info(&chip_info);
        esp_efuse_mac_get_default(mac);

        ESP_LOGI("Chip Info", "Serial number (MAC address): %02X:%02X:%02X:%02X:%02X:%02X",
                 mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

        ESP_LOGI("Chip Info", "This is an ESP32 chip with %d CPU cores, WiFi%s%s",
                 chip_info.cores,
                 (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                 (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

        ESP_LOGI("Chip Info", "Chip revision: %d", chip_info.revision);

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    // Initialize Wi-Fi
    wifi_init_sta();

    // Create the task to print chip information
    xTaskCreate(&print_chip_info_task, "print_chip_info_task", 2048, NULL, 5, NULL);
}
