#include "headers.h"

/**
 * open the 'os-relese' file, read the 'NAME_PRETTY' field, store it in a
 * dynamically allocated character array and return it
*/
char *get_distro_name()
{
    FILE *os_release_fp = fopen("/etc/os-release", "r");
    if(os_release_fp == NULL)
        perror("Failed to open \'/etc/os-release\'"), exit(1);

    char *line = (char *)malloc(LINE_LEN * sizeof(char));
    if(line == NULL)
        perror("\'get_distro_name\' failed"), exit(1);

    // get every line until the 'PRETTY_NAME' line
    do
    {
        fgets(line, LINE_LEN, os_release_fp);
    } while(strstr(line, "PRETTY") == NULL);

    // seek back at the start of the 'PRETTY_NAME' line
    fseek(os_release_fp, -strlen(line), SEEK_CUR);
    // skip the 'PRETTY_NAME="' part of the line
    fseek(os_release_fp, NAME_PRETTY_LINE_OFFSET, SEEK_CUR);

    // get the remaining characters in the line 
    // and get rid of the trailing " character
    fgets(line, LINE_LEN, os_release_fp);
    line[strcspn(line, "\"")] = 0;

    // close the file stream and return the name
    fclose(os_release_fp);
    return line;
}

/**
 * execute 'uname -r', get the output, put it in a string and return it
*/
char *get_kernel_version()
{
    // 'popen' executes the command and returns a pointer to the output stream
    FILE *uname_r_fp = popen("uname -r", "r");
    if(!uname_r_fp)
        perror("Failed to execute \'uname -r\'"), exit(1);

    char *kern_ver = (char *)malloc(LINE_LEN * sizeof(char));
    if(!kern_ver)
        perror("\'get_kernel_version\' failed"), exit(1);

    // read a full line from the output (there's only one for uname -r)
    fgets(kern_ver, LINE_LEN, uname_r_fp);
    kern_ver[strcspn(kern_ver, "\n")] = 0;

    // close the stream
    pclose(uname_r_fp);

    return kern_ver;
}

/**
 * execute 'whoami', get the output, put it in a string and return it
*/
char *get_username()
{
    // execute 'whoami'
    FILE *username_fp = popen("whoami", "r");
    if(!username_fp)
        perror("Failed to execute \'whoami\'"), exit(1);

    char *username = (char *)malloc(LINE_LEN * sizeof(char));
    if(!username)
        perror("\'get_username\' failed"), exit(1);

    // get the output and strip the trailing '\n'
    fgets(username, LINE_LEN, username_fp);
    username[strcspn(username, "\n")] = 0;

    // close the stream and return the output
    pclose(username_fp);
    return username;
}

/**
 * Get the hostname from '/etc/hostname', put it in a string and return it
*/
char *get_hostname()
{
    // execute 'hostname'
    FILE *hostname_fp = popen("cat /etc/hostname", "r");
    if(!hostname_fp)
        perror("Failed to execute \'hostname\'"), exit(1);

    char *hostname = (char *)malloc(LINE_LEN * sizeof(char));
    if(!hostname)
        perror("\'get_hostname\' failed"), exit(1);

    // put the output in a string and strip the trailing '\n'
    fgets(hostname, LINE_LEN, hostname_fp);
    hostname[strcspn(hostname, "\n")] = 0;

    // close the stream and return the output
    pclose(hostname_fp);
    return hostname;
}

/**
 * execute `echo $SHELL` to get the current shell
*/
char *get_shell()
{
    // open a stream to the output of `echo $SHELL`
    FILE *shell_fp = popen("echo $SHELL", "r");
    if(shell_fp == NULL)
        perror("Failed to execute \'exho $SHELL\'"), exit(1);

    char *shell = (char *)malloc(LINE_LEN * sizeof(char));
    if(shell == NULL)
        perror("\'get_shell\' failed"), exit(1);

    // Get the shell path from the output and remove the trailing newline char
    fgets(shell, LINE_LEN, shell_fp);
    shell[strcspn(shell, "\n")] = 0;

    // check for common shell names in the output path
    // when one is found replace the content of 'shell' with the shell name
    if(strstr(shell, "zsh") != NULL)
        strcpy(shell, "zsh");
    else if(strstr(shell, "bash") != NULL)
        strcpy(shell, "bash");
    else if(strstr(shell, "fish") != NULL)
        strcpy(shell, "fish");

    // close the stream and return the shell name
    pclose(shell_fp);
    return shell;
}

/**
 * compare the 'os_name' string to an abbreviation of the various distros' names
 * and return the correct one
*/
char *print_icon(char *os_name)
{
    // create a new array with the same size as the original one
    char *tmp = (char *)malloc(strlen(os_name) * sizeof(char));
    if(tmp == NULL)
        perror("\'print_icon\' failed"), exit(1);

    // copy the os name to the tmp array and lowercase the distro name
    strcpy(tmp, os_name);
    for(int i = 0; i < strlen(tmp); i++)
    {
        tmp[i] = tolower(tmp[i]);
    }

    // compare the result to every available shortened distro name
    // when the distro is found the tmp array is freed and the right symbol
    // code is returned
    if(strstr(tmp, "alpine"))
    {
        free(tmp);
        return ALPINE;
    }
    else if(strstr(tmp, "alma"))
    {
        free(tmp);
        return ALMALINUX;
    }
    else if(strstr(tmp, "arch"))
    {
        free(tmp);
        return ARCH;
    }
    else if(strstr(tmp, "artix"))
    {
        free(tmp);
        return ARTIX;
    }
    else if(strstr(tmp, "centos"))
    {
        free(tmp);
        return CENTOS;
    }
    else if(strstr(tmp, "debian"))
    {
        free(tmp);
        return DEBIAN;
    }
    else if(strstr(tmp, "elementary"))
    {
        free(tmp);
        return ELEMENTARY;
    }
    else if(strstr(tmp, "endeavour"))
    {
        free(tmp);
        return ENDEAVOUR;
    }
    else if(strstr(tmp, "fedora"))
    {
        free(tmp);
        return FEDORA;
    }
    else if(strstr(tmp, "gentoo"))
    {
        free(tmp);
        return GENTOO;
    }
    else if(strstr(tmp, "kali"))
    {
        free(tmp);
        return KALI;
    }
    else if(strstr(tmp, "manjaro"))
    {
        free(tmp);
        return MANJARO;
    }
    else if(strstr(tmp, "mint"))
    {
        free(tmp);
        return MINT;
    }
    else if(strstr(tmp, "nix"))
    {
        free(tmp);
        return NIXOS;
    }
    else if(strstr(tmp, "opensuse"))
    {
        free(tmp);
        return OPENSUSE;
    }
    else if(strstr(tmp, "pop"))
    {
        free(tmp);
        return POPOS;
    }
    else if(strstr(tmp, "redhat"))
    {
        free(tmp);
        return REDHAT;
    }
    else if(strstr(tmp, "rocky"))
    {
        free(tmp);
        return ROCKYLINUX;
    }
    else if(strstr(tmp, "slackware"))
    {
        free(tmp);
        return SLACKWARE;
    }
    else if(strstr(tmp, "ubuntu"))
    {
        free(tmp);
        return UBUNTU;
    }
    else if(strstr(tmp, "void"))
    {
        free(tmp);
        return VOIDLINUX;
    }
    else if(strstr(tmp, "zorin"))
    {
        free(tmp);
        return ZORINOS;
    }
    else
    {
        free(tmp);
        return GENERIC;
    }
}

/**
 * free the memory from the data structure containing the os infos
*/
void free_all(os_info_t *os_info_struct)
{
    free(os_info_struct->hostname);
    free(os_info_struct->kernel_version);
    free(os_info_struct->os_name);
    free(os_info_struct->shell);
    free(os_info_struct->username);
}
