// veronicarecomp - ReXGlue Recompiled Project
//
// Code Veronica RexGue Cvars

#pragma once

#include <rex/rex_app.h>
#include <rex/cvar.h>
#include <rex/ui/keybinds.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <format>

namespace CodeVeronica {
    class VeronicaRecompSettings  {
        public:
            struct ConfigSetting {
                std::string name;
                std::string value;
            };

            static void SetDefaultPaths(rex::PathConfig& paths);
            static void InitializeSettings(const rex::PathConfig& paths, rex::ui::Window *curWindow);
            static void InitializeSettingsList(std::string name, std::vector<ConfigSetting> settings);

        private:
            inline static const std::string _title = "Resident Evil CODE:Veronica"; // Window title
            inline static const std::string _version = "0.0.1"; // Application version
            inline static const std::vector<ConfigSetting> _requiredSettings = { // Required Settings 
                //DX12
                {"render_target_path_d3d12","rtv"}, 
                {"d3d12_readback_resolve", "false"}, 
                {"d3d12_readback_memexport", "false"}, 
                {"d3d12_submit_on_primary_buffer_end", "false"}, 
                {"d3d12_allow_variable_refresh_rate_and_tearing","true"},

                //Vulkan
                {"vulkan_allow_present_mode_immediate", "true"},

                //Texture cache
                {"texture_cache_memory_limit_render_to_texture","256"},
                {"texture_cache_memory_limit_soft","4096"},
                {"texture_cache_memory_limit_hard","8192"},
                {"texture_cache_memory_limit_soft_lifetime","3600"},

                //Other
                {"audio_maxqframes","16"}, // Increasing might reduce performance
                {"readback_resolve", "full"}, // Increases performance when set to full.
                {"readback_memexport", "false"}, 
                {"clear_memory_page_state", "false"}, // Performance gain by reducing CPU overhead. Could also cause instability.
                ///{"execute_unclipped_draw_vs_on_cpu", "true"},
                {"gpu_allow_invalid_fetch_constants", "false"},
                {"snorm16_render_target_full_range", "false"}, // It breaks lighting when enabled!
            };
            inline static const std::vector<ConfigSetting> _defaultConfig = { // Default Settings
                //Graphic Settings
                {"native_2x_msaa", "true"},
                {"anisotropic_override", "2"},
                {"resolution_scale", "2"},
                //Vsync
                {"vsync","true"},
                {"video_mode_refresh_rate","60"},
            };
    };
}