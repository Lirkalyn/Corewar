
int	conv_conv(int var)
{
    int   tmp;

    tmp = 0;
    tmp = (var & 0xFF000000) >> 24;
    tmp |= ((var & 0x00FF0000) >> 8);
    tmp |= (var & 0x0000FF00) << 8;
    tmp |= ((var & 0x000000FF) << 24);
    return (tmp);
}


int	live_f(char **the_info, int fd)
{
    char hexa;
    int	arg;

    hexa = 0x01;
    if (write(fd, &hexa, sizeof(hexa)) == -1)
        return (1);
    arg = my_getnbr(&the_info[1]);
    arg = conv_conv(arg);
    if (write(fd, &arg, sizeof(arg)) == -1)
        return (1);
    return (0);
}

int	ld_f(thewall_t thewall_t)
{

}

