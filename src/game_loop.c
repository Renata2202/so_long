/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:51:56 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/19 16:37:43 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h" // Supondo que essa seja a header com as declarações

void game_loop(t_game *game)
{
    // 1. Ler os inputs do jogador
    // Aqui você verificaria se o jogador pressionou as teclas de movimento
    if (game->input.up)
        move_player(game, 0, -1); // Movimenta para cima
    else if (game->input.down)
        move_player(game, 0, 1);  // Movimenta para baixo
    else if (game->input.left)
        move_player(game, -1, 0); // Movimenta para a esquerda
    else if (game->input.right)
        move_player(game, 1, 0);  // Movimenta para a direita

    // 2. Atualizar o estado do jogo
    // Exemplo: Verificar se o jogador pegou um coletável
    if (game->map[game->player.y][game->player.x] == 'C') {
        game->collectibles--; // Diminui o número de coletáveis
        game->map[game->player.y][game->player.x] = '0'; // Marca a posição como vazia
    }

    // Verificar se o jogador alcançou a saída após pegar todos os coletáveis
    if (game->collectibles == 0 && game->map[game->player.y][game->player.x] == 'E') {
        // O jogador venceu
        printf("Você venceu!\n");
        exit(0); // Encerra o jogo
    }

    // 3. Renderizar o jogo
    render_map(game); // Função que desenha o mapa e os elementos na janela
    render_player(game); // Função que desenha o jogador na nova posição

    // 4. Verificar as condições de vitória ou derrota (já incluído acima)
}
