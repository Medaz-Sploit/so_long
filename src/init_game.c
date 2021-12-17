void        init_game(t_so_long so_long)
{
    player_position();
    texture();
    sprite();
    mlx_hook(so_long.win_ptr, 2, 0, key_press, "KEY_PRESS");
    mlx_hook(so_long.win_ptr, 3, 0, key_release, "KEY_RELEASE");
    mlx_loop_hook(so_long.mlx_ptr, &game_update, "GAME_UPDATE");
    mlx_hook(so_long.win_ptr, 17, 1L << 5, key_exit, "EXIT_GAME");
    mlx_loop(so_long.mlx_ptr);
}
