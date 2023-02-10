#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * general layout and technical macros
*/
#define LINE_LEN                512 // maximum line length
#define NAME_PRETTY_LINE_OFFSET 13  // amount of chars to skip in the `NAME_PRETTY` line
#define PADDING                 10  // padding of the left labels in the output

/**
 * output icons
*/
#define USER_ICON   "\uf007"
#define HOST_ICON   "\uf878"
#define KERNEL_ICON "\uf0ad"
#define SHELL_ICON  "\ue795"

/**
 * bold text colors
*/
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define RST  "\e[0m"

/**
 * distro symbols
 * you can test these symbols in your shell via 'echo "<symbol code>"'
*/
#define ALPINE      "\uf300"
#define ALMALINUX   "\uf31d"
#define ARCH        "\uf303"
#define ARTIX       "\uf31f"
#define CENTOS      "\uf304"
#define DEBIAN      "\uf306"
#define DEEPIN      "\uf321"
#define ELEMENTARY  "\uf309"
#define ENDEAVOUR   "\uf322"
#define FEDORA      "\uf30a"
#define GENTOO      "\uf30d"
#define KALI        "\uf327"
#define MANJARO     "\uf312"
#define MINT        "\uf30e"
#define NIXOS       "\uf313"
#define OPENSUSE    "\uf314"
#define POPOS       "\uf32a"
#define REDHAT      "\uf316"
#define ROCKYLINUX  "\uf32b"
#define SLACKWARE   "\uf318"
#define UBUNTU      "\uf31b"
#define VOIDLINUX   "\uf32e"
#define ZORINOS     "\uf32f"
#define GENERIC     "\uf31a"

/**
 * struct containing the various system informations
*/
typedef struct os_info_t
{
    char *os_name;          // OS name fetched from '/etc/os-release'
    char *kernel_version;   // kernel version fetched via 'uname -r'
    char *username;         // username fetched via 'whoami'
    char *hostname;         // hostname fetched from '/etc/hostname'
    char *shell;            // shell fetched via 'echo $SHELL'
} os_info_t;

/**
 * functions prototypes
*/
char *get_distro_name();
char *get_kernel_version();
char *get_username();
char *get_hostname();
char *get_shell();
char *print_icon(char *os_name);
void free_all(os_info_t *os_info_struct);

#endif
