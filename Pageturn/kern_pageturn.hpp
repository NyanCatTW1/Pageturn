//  SPDX-FileCopyrightText: © 2023 NyanCatTW1 <a0939712328@gmail.com>
//  SPDX-License-Identifier: MIT

#pragma once
#include <Headers/kern_patcher.hpp>

class Pageturn {
    public:
    static Pageturn *callback;

    void init();
    void processPatcher(KernelPatcher &patcher);

    private:
};
