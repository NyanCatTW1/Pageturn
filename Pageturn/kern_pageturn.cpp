//  SPDX-FileCopyrightText: © 2023 NyanCatTW1 <a0939712328@gmail.com>
//  SPDX-License-Identifier: MIT

#include "kern_pageturn.hpp"
#include <Headers/kern_api.hpp>

Pageturn *Pageturn::callback = nullptr;

void Pageturn::init() {
    callback = this;

    lilu.onPatcherLoadForce(
        [](void *user, KernelPatcher &patcher) { static_cast<Pageturn *>(user)->processPatcher(patcher); }, this);
}

void Pageturn::processPatcher(KernelPatcher &patcher) {}