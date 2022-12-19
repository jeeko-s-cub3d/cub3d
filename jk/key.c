#include "cub3d.h"

int	key_press(int keycode, t_all *p_all)
{
	if (keycode == K_W)
		p_all->key.up = true;
	else if (keycode == K_S)
		p_all->key.down = true;
	else if (keycode == K_A)
		p_all->key.left = true;
	else if (keycode == K_D)
		p_all->key.right = true;
	else if (keycode == K_AR_U)
		p_all->key.updown_sight = -1;
	else if (keycode == K_AR_D)
		p_all->key.updown_sight = 1;
	else if (keycode == K_AR_R)
		p_all->key.right_rotation = true;
	else if (keycode == K_AR_L)
		p_all->key.left_rotation = true;
	else if (keycode == K_ESC)
		exit(0);
	
    return (0);
}

int	key_release(int keycode, t_all *p_all)
{
	if (keycode == K_W)
		p_all->key.up = false;
	else if (keycode == K_S)
		p_all->key.down = false;
	else if (keycode == K_A)
		p_all->key.left = false;
	else if (keycode == K_D)
		p_all->key.right = false;
	else if (keycode == K_AR_U)
		p_all->key.updown_sight = false;
	else if (keycode == K_AR_D)
		p_all->key.updown_sight = false;
	else if (keycode == K_AR_R)
		p_all->key.right_rotation = false;
	else if (keycode == K_AR_L)
		p_all->key.left_rotation = false;
	else if (keycode == K_ESC)
		exit(0);
        
	return (0);
}
