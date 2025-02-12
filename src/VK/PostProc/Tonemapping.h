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

#include "PostProcPS.h"
#include "base/ResourceViewHeaps.h"

namespace CAULDRON_VK
{
    class ToneMapping
    {
    public:
        void OnCreate(Device* pDevice, VkRenderPass renderPass, ResourceViewHeaps *pResourceViewHeaps, StaticBufferPool  *pStaticBufferPool, DynamicBufferRing *pDynamicBufferRing, uint32_t srvTableSize = 1, const char* shaderSource = "Tonemapping.glsl");
        void OnDestroy();

        void UpdatePipelines(VkRenderPass renderPass);

        void Draw(VkCommandBuffer cmd_buf, VkImageView HDRSRV, float exposure, int toneMapper);

    protected:
        Device* m_pDevice;
        ResourceViewHeaps *m_pResourceViewHeaps;

        PostProcPS m_toneMapping;
        DynamicBufferRing *m_pDynamicBufferRing = NULL;

        VkSampler m_sampler;

        uint32_t              m_descriptorIndex;
        static const uint32_t s_descriptorBuffers = 10;

        VkDescriptorSet       m_descriptorSet[s_descriptorBuffers];
        VkDescriptorSetLayout m_descriptorSetLayout;

        struct ToneMappingConsts { float exposure; int toneMapper; };
    };
}
