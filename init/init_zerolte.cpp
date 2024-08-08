/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>
#include <android-base/properties.h>

#include "init_universal7420.h"

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;

void set_sim_info()
{
	const char *simslot_count_path = "/proc/simslot_count";
	std::string simslot_count;

	if (ReadFileToString(simslot_count_path, &simslot_count)) {
		simslot_count = Trim(simslot_count); // strip newline
		property_override("ro.multisim.simslotcount", simslot_count.c_str());
		property_override("ro.vendor.multisim.simslotcount", simslot_count.c_str());
	}
	else {
		LOG(ERROR) << "Could not open '" << simslot_count_path << "'\n";
	}
}

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G925F") == 0) {
        property_override("ro.build.description", "zeroltexx-user 7.0 NRD90M G925FXXU6EVG1 release-keys");
        set_ro_product_prop("device", "zeroltexx");
        set_ro_build_prop("fingerprint", "samsung/zeroltexx/zerolte:7.0/NRD90M/G925FXXU6EVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G925F");
        set_ro_product_prop("name", "zeroltexx");
        gsm_properties("9");
    } else if (bootloader.find("G925I") == 0) {
        property_override("ro.build.description", "zeroltexx-user 7.0 NRD90M G925IDVU4FVHG release-keys");
        set_ro_product_prop("device", "zeroltexx");
        set_ro_build_prop("fingerprint", "samsung/zeroltexx/zerolte:7.0/NRD90M/G925IDVU4FVHG:user/release-keys");
        set_ro_product_prop("model", "SM-G925I");
        set_ro_product_prop("name", "zeroltexx");
        gsm_properties("9");
    } else if (bootloader.find("G925K") == 0) {
        property_override("ro.build.description", "zeroltektt-user 7.0 NRD90M G925KKKU3EVG1 release-keys");
        set_ro_product_prop("device", "zeroltektt");
        set_ro_build_prop("fingerprint", "samsung/zeroltektt/zerolte:7.0/NRD90M/G925KKKU3EVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G925K");
        set_ro_product_prop("name", "zeroltektt");
        gsm_properties("9");
    } else if (bootloader.find("G925W8") == 0) {
        property_override("ro.build.description", "zeroltecan-user 7.0 NRD90M G920W8VLU6DVG1 release-keys");
        set_ro_product_prop("device", "zeroltebmc");
        set_ro_build_prop("fingerprint", "samsung/zeroltecan/zeroltecan:7.0/NRD90M/G920W8VLU6DVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G925W8");
        set_ro_product_prop("name", "zeroltebmc");
        gsm_properties("9");
    } else if (bootloader.find("G925S") == 0) {
        property_override("ro.build.description", "zerolteskt-user 7.0 NRD90M G925SKSU3EVG1 release-keys");
        set_ro_product_prop("device", "zerolteskt");
        set_ro_build_prop("fingerprint", "samsung/zerolteskt/zerolte:7.0/NRD90M/G925SKSU3EVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G925S");
        set_ro_product_prop("name", "zerolteskt");
        gsm_properties("9");
    }  else if (bootloader.find("G925L") == 0) {
        property_override("ro.build.description", "zeroltelgt-user 7.0 NRD90M G925LKLU3EVG1 release-keys");
        set_ro_product_prop("device", "zeroltelgt");
        set_ro_build_prop("fingerprint", "samsung/zeroltelgt/zeroltelgt:7.0/NRD90M/G925LKLU3EVG1:user/release-keys");
        set_ro_product_prop("model", "SM-G925L");
        set_ro_product_prop("name", "zeroltelgt");
        gsm_properties("9");
    } else if (bootloader.find("G925T") == 0) {
        property_override("ro.build.description", "zeroltetmo-user 7.0 NRD90M G925TUVU6FVH1 release-keys");
        set_ro_product_prop("device", "zeroltetmo");
        set_ro_build_prop("fingerprint", "samsung/zeroltetmo/zerolte:7.0/NRD90M/G925TUVU6FVH1:user/release-keys");
        set_ro_product_prop("model", "SM-G925T");
        set_ro_product_prop("name", "zeroltetmo");
        gsm_properties("9");
    } else if (bootloader.find("G925P") == 0) {
        property_override("ro.build.description", "zerolteskt-user 7.0 NRD90M G925PVPS4DRC2 release-keys");
        set_ro_product_prop("device", "zerolteskt");
        set_ro_build_prop("fingerprint", "samsung/zerolteskt/zerolte:7.0/NRD90M/G925PVPS4DRC2:user/release-keys");
        set_ro_product_prop("model", "SM-G925S");
        set_ro_product_prop("name", "zerolteskt");
        gsm_properties("9");
    } else {
        gsm_properties("9");
    }

    set_sim_info();
    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}
