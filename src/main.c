#include "headers.h"

int main()
{
    // declare the struct containing the needed data
    os_info_t *os_info = create_os_info_struct();

    // initialize the struct
    gather_os_infos(os_info);

    // top padding
    printf("\n");

    // formatted output
    printf(BRED "%*s" RST "  %s  " BRED "%s\n" RST,
        PADDING,
        USER_LABEL,
        USER_ICON,
        os_info->username);

    printf(BGRN "%*s" RST "  %s  " BGRN "%s\n" RST,
        PADDING,
        HOST_LABEL,
        HOST_ICON,
        os_info->hostname);

    printf(BBLU "%*s" RST "  %s  " BBLU "%s\n" RST,
        PADDING,
        DISTRO_LABEL,
        print_icon(os_info->os_name),
        os_info->os_name);

    printf(BYEL "%*s" RST "  %s  " BYEL "%s\n" RST,
        PADDING,
        KERNEL_LABEL,
        KERNEL_ICON,
        os_info->kernel_version);

    printf(BMAG "%*s" RST "  %s  " BMAG "%s\n" RST,
        PADDING,
        SHELL_LABEL,
        SHELL_ICON,
        os_info->shell);

    // bottom padding
    printf(" \n");

    // free the memory before exiting
    free_os_info_struct(os_info);
    free(os_info);

    return 0;
}
