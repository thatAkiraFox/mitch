#include "headers.h"

int main()
{
    // declare the struct containing the needed data
    os_info_t os_info;

    // initialize the struct
    os_info.os_name = get_distro_name();
    os_info.kernel_version = get_kernel_version();
    os_info.username = get_username();
    os_info.hostname = get_hostname();
    os_info.shell = get_shell();

    // print formatted infos
    printf(BRED "\n%*s" RST "  %s  " BRED "%s\n" RST,
        PADDING,
        "User",
        USER_ICON,
        os_info.username);

    printf(BGRN "%*s" RST "  %s  " BGRN "%s\n" RST,
        PADDING,
        "Host",
        HOST_ICON,
        os_info.hostname);

    printf(BBLU "%*s" RST "  %s  " BBLU "%s\n" RST,
        PADDING,
        "Distro",
        print_icon(os_info.os_name),
        os_info.os_name);

    printf(BYEL "%*s" RST "  %s  " BYEL "%s\n" RST,
        PADDING,
        "Kernel",
        KERNEL_ICON,
        os_info.kernel_version);

    printf(BMAG "%*s" RST "  %s  " BMAG "%s\n" RST "\n",
        PADDING,
        "Shell",
        SHELL_ICON,
        os_info.shell);

    free_all(&os_info);

    return 0;
}
