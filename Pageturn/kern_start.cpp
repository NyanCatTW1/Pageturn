//  SPDX-FileCopyrightText: © 2023 NyanCatTW1 <a0939712328@gmail.com>
//  SPDX-License-Identifier: MIT

#include "kern_pageturn.hpp"
#include <Headers/kern_api.hpp>
#include <Headers/kern_version.hpp>
#include <Headers/plugin_start.hpp>

static Pageturn pageturn;

static const char *bootargOff = "-pageturnoff";
static const char *bootargDebug = "-pageturndbg";
static const char *bootargBeta = "-pageturnbeta";

PluginConfiguration ADDPR(config) {
    xStringify(PRODUCT_NAME),
    parseModuleVersion(xStringify(MODULE_VERSION)),
    LiluAPI::AllowNormal | LiluAPI::AllowInstallerRecovery | LiluAPI::AllowSafeMode,
    &bootargOff,
    1,
    &bootargDebug,
    1,
    &bootargBeta,
    1,
    KernelVersion::BigSur,
    KernelVersion::Sonoma,
    []() { pageturn.init(); },
};
