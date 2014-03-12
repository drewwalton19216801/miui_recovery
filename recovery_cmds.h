/*
 * Copyright (C) 2013 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _RECOVERY_CMDS_H
#define _RECOVERY_CMDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>

//#include "extendedcommands.h"
#include "nandroid.h"
#include "dedupe/dedupe.h"

extern int flash_image_main(int argc, char **argv);
extern int dump_image_main(int argc, char **argv);
extern int erase_image_main(int argc, char **argv);
extern int mkyaffs2image_main(int argc, char **argv);
extern int unyaffs_main(int argc, char **argv);
extern int reboot_main(int argc, char **argv);
extern int poweroff_main(int argc, char **argv);
extern int setprop_main(int argc, char **argv);
extern int getprop_main(int argc, char **argv);
extern int fsck_msdos_main(int argc, char **argv);
extern int newfs_msdos_main(int argc, char **argv);
extern int vdc_main(int argc, char **argv);
extern int sdcard_main(int argc, char **argv);
#ifdef USE_F2FS
extern int make_f2fs_main(int argc, char **argv);
extern int fsck_f2fs_main(int argc, char **argv);
extern int fibmap_main(int argc, char **argv);
#endif
#ifdef RECOVERY_HAVE_SELINUX
extern int getenforce_main(int argc, char **argv);
extern int setenforce_main(int argc, char **argv);
extern int chcon_main(int argc, char **argv);
extern int runcon_main(int argc, char **argv);
extern int getsebool_main(int argc, char **argv);
extern int setsebool_main(int argc, char **argv);
extern int load_policy_main(int argc, char **argv);
extern int restorecon_main(int argc, char **argv);
#endif

struct recovery_cmd {
    const char *name;
    int (*main_func)(int argc, char **argv);
};

static const struct recovery_cmd recovery_cmds[] = {
    { "dedupe",         dedupe_main },
    { "flash_image",    flash_image_main },
    { "dump_image",     dump_image_main },
    { "erase_image",    erase_image_main },
    { "mkyaffs2image",  mkyaffs2image_main },
    { "unyaffs",        unyaffs_main },
    { "nandroid",       nandroid_main },
    { "bu",             bu_main },
    { "reboot",         reboot_main },
    { "poweroff",       reboot_main },
    { "setprop",        setprop_main },
    { "getprop",        getprop_main },
    { "fsck_msdos",     fsck_msdos_main },
    { "newfs_msdos",    newfs_msdos_main },
    { "vdc",            vdc_main },
    { "sdcard",         sdcard_main },
#ifdef USE_F2FS
    { "mkfs.f2fs",      make_f2fs_main },
    { "fsck.f2fs",      fsck_f2fs_main },
    { "fibmap.f2fs",    fibmap_main },
#endif
#ifdef RECOVERY_HAVE_SELINUX
    { "getenforce",      getenforce_main },
    { "setenforce",      setenforce_main },
    { "restorecon",      restorecon_main },
    { "chcon",          chcon_main },
    { "runcon",         runcon_main },
    { "getsebool",      getsebool_main },
    { "setsebool",      setsebool_main },
    { "load_policy",    load_policy_main },
#endif
    { NULL, NULL },
};

inline struct recovery_cmd get_command(char* command) {
    int i;

    for (i = 0; recovery_cmds[i].name; i++) {
        if (strcmp(command, recovery_cmds[i].name) == 0)
            break;
    }

    return recovery_cmds[i];
}


#ifdef __cplusplus
}
#endif

#endif
