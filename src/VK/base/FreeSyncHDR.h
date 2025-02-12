// AMD Cauldron code
// 
// Copyright(c) 2018 Advanced Micro Devices, Inc.All rights reserved.
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
#pragma once

#include "DeviceProperties.h"
#include "InstanceProperties.h"
#include <vulkan/vulkan_win32.h>

namespace CAULDRON_VK
{
    enum PresentationMode
    {
        PRESENTATIONMODE_WINDOWED,
        PRESENTATIONMODE_BORDERLESS_FULLSCREEN,
        PRESENTATIONMODE_EXCLUSIVE_FULLSCREEN
    };

    enum DisplayMode
    {
        DISPLAYMODE_SDR,
        DISPLAYMODE_FSHDR_Gamma22,
        DISPLAYMODE_FSHDR_SCRGB,
        DISPLAYMODE_HDR10_2084,
        DISPLAYMODE_HDR10_SCRGB
    };

    // only the swapchain should be using these functions

    bool fsHdrInit(VkDevice device, VkSurfaceKHR surface, VkPhysicalDevice physicalDevice, HWND hWnd);
    bool fsHdrEnumerateDisplayModes(std::vector<DisplayMode> *pModes, bool includeFreesyncHDR, PresentationMode fullscreenMode = PRESENTATIONMODE_WINDOWED, bool enableLocalDimming = true);
    VkSurfaceFormatKHR fsHdrGetFormat(DisplayMode displayMode);
    bool fsHdrSetDisplayMode(DisplayMode displayMode, VkSwapchainKHR swapChain);
    const char *fsHdrGetDisplayModeString(DisplayMode displayMode);
    const VkHdrMetadataEXT* fsHdrGetDisplayInfo();

    void fsHdrSetLocalDimmingMode(VkSwapchainKHR swapchain, VkBool32 localDimmingEnable);
    void fsHdrSetFullscreenState(bool fullscreen, VkSwapchainKHR swapchain);

    void fsHdrGetPhysicalDeviceSurfaceCapabilities2KHR(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface, VkSurfaceCapabilitiesKHR *pSurfCapabilities);
    VkSurfaceFullScreenExclusiveInfoEXT *GetVkSurfaceFullScreenExclusiveInfoEXT();

    const bool CheckIfWindowModeHdrOn();
}
