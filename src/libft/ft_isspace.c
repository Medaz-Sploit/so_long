int     ft_isspace(char c)
{
    if (c == '\t' || c == '\r' || c == ' ' || c == '\v')
        return (1);
    return (0);
}
