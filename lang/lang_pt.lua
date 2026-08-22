-- UNFINISHED!! do not implement

langdata["pt"] = -- the letters here will be what you type for the command (ex: to switch to this language, type "/lang en")
{
	-- fullname for auto select (make sure this matches in-game under Misc -> Languages)
	fullname = "Português",

	-- name in the built-in menu
	name_menu = "Português",

	-- replace "English" with the name of this language
	switched = "Trocado para o português!",

	served = "%s servido.",
	dish_not_valid = "Isso não é um prato válido!",
	needs_plate = "Você precisa de um prato!",
	plate_empty = "O prato está vazio.",
	no_orders_available = "Nenhum pedido disponível.",
	order_not_availble = "Esse pedido não está disponível.",
	playing_now = "Você está jogando agora!",
	too_many_cooks = "Há muitos cozinheiros na cozinha! Por favor espere até que uma vaga seja liberada.",
	connection_issues = "Algumas pessoas podem estar tendo problemas de conexão:",
	fix_desync = "Tentando arrumar a desincronização...",
	waiting_for_host = "Esperando o host...",
	press_start = "Aperte [START]",
	time_format = "%d:%02d",
	short_player_count = "%dP",

	tip = "Dica: ",
	kitchen = "Cozinha",
	spawn_point = "Ponto de spawn",
	ready = "Pronto!",
	taken = "Vaga ocupada",
	confirm_key = "[A] Confirmar",
	cook_done = "Pronto",

	-- NOTE: Don't translate the text inside brackets ([GRAB], etc.)
	level_name_0 = "Nível de Teste",
	level_desc_0 = "Nível de depuração contendo todas as mecânicas. Extremamente desafiador!",

	level_name_1 = "Bob-Omb Saladfield",
	level_desc_1 = "Um nível simples com salada que ensina as mecânicas básicas. Comece aqui!",
	level_advice_1 = "Aperte [GRAB] para pegar ingredientes, e segure [ACTION] on a cutting board to cut them.",
	
	level_name_2 = "Whomp's Spinning Salads",
	level_desc_2 = "Caminhe cuidadosamente pelas plataformas giratórias para preparar saladas, e não se esqueça de lavar a louça!",
	level_advice_2 = "Leve pratos sujos para a pia e segure [ACTION] para lavar-los.",

	level_name_3 = "Soupy Sea",
	level_desc_3 = "Aprenda a fazer sopa, mas tome cuidado, As bancadas vão se mexer com o movimento do barco...",
	level_advice_3 = "Você não consegue atravessar por barreiras vermelhas, mas os ingredientes conseguem.",

	level_name_4 = "Lethal Lava Puzzle",
	level_desc_4 = "Faça mais sopa, mas olhe onde você anda! Se você ficar em cima de uma peça de quebra-cabeça, você vai ser derrubado na lava!",
	level_advice_4 = "Ingredientes serão destruídos se cairem na lava.",

	level_name_5 = "Shifting Sand Burgers",
	level_desc_5 = "Aprenda a fazer hambúrgueres, mas não caia na areia movediça!",
	level_advice_5 = "Para preparar hambúrgueres, corte um pouco de carne e grelhe o hambúrguer, depois coloque no pão e acrescente os outros ingredientes.",

	level_name_6 = "Burger Time",
	level_desc_6 = "Faça hambúrgueres mais complexos! Use o impluso na parede para alcançar os ingredientes!",
	level_advice_6 = "Press [THROW] to throw raw ingredients. Ingredients will bounce off of walls when thrown.",
	-- wall kick has different names in portuguese... some i've seen are: salto escalada, impluso na parede (playtronic guide).........

	level_name_7 = "Rainbow Cruise",
	level_desc_7 = "Put burgers and salad together on this carpet ride! Take advantage of when the carpets are together!",
	level_advice_7 = "Lembre-se de jogar ingredientes crus com [THROW]!", -- ?

	level_name_8 = "Slip Slidin' Pizzas",
	level_desc_8 = "Become aquainted with the realm of Pizza. Slide down to access the lower area quickly, but don't slip off of the mountain!",
	level_advice_8 = "Make pizza by combining cut dough, tomato, cheese, and other toppings, then baking the pizza in an oven.",

	level_name_9 = "Merry Go Pizza",
	level_desc_9 = "Make Pizzas with multiple toppings in this chaotic merry go round... if you dare!",
	level_advice_9 = "You can't add toppings to pizzas once they're fully baked.",

	level_name_10 = "Koopa Kitchen",
	level_desc_10 = "O desafio final! Você terá que preparar todos os tipos de comida de uma vez só..",

	menu_on = "\\#50ff50\\Ligado",
	menu_off = "\\#ff5050\\Desligado",
	menu_yes = "Sim",
	menu_no = "Não",
	menu_no_desc = "Sem descrição disponível.",
	menu_title_default = "Menu",
	menu_left = "Esquerda",
	menu_right = "Direita",
	menu_left_offset = "Mover da Esquerda",
	menu_right_offset = "Mover da Direita",
	menu_left_to_right = "Esquerda para Direita",
	menu_right_to_left = "Direita para Esquerda",

	menu_continue = "Continuar",
	menu_retry = "Tentar de novo",
	menu_quit = "Sair",
	menu_level_select = "Seleção de Níveis",
	menu_host_options = "Opções do Host",
	menu_spectate = "Espectar",
	menu_practice = "Praticar",
	menu_quit_practice = "Sair da Prática",
	menu_preferences = "Preferências",
	menu_records = "Recordes",
	menu_djui_menu = "Menu DJUI",

	menu_grab_button = "Botão de Pegar",
	menu_action_button = "Botão de Ação",
	menu_throw_button = "Botão de Arremessar",
	menu_reduced_motion = "Movimento de menu reduzido",
	menu_order_hud_location = "Order Hud Location",
	menu_order_priority = "Prioridade de pedidos",
	menu_cook_indicators = "Cook/Burn Subtitles",
	menu_disable_water_effect = "Desativar efeito d'água.",
	menu_language = "Linguagem",

	menu_join_now = "Me coloque!",
	menu_join_wait = "Espere pelo o fim do nível",
	menu_join_practice = "Aprenda a cozinhar",
	menu_join_spectate = "Só quero assistir",

	menu_players = "Jogadores",
	menu_overall = "Overall",
	menu_record_best_players = "Best %dP:",
	menu_record_best_stars = "Best Stars:",
	menu_record_best_overall = "Best Overall:",

	menu_auto_start = "Auto Start",
	menu_allow_mid_game_join = "Permitir entrar no meio do jogo",

	menu_desc_continue = "Despausar o jogo.",
	menu_desc_restart = "Reiniciar o nível.",
	menu_desc_quit = "Sair do jogo.",
	menu_desc_level_select = "Selecione um nível para começar.",
	menu_desc_host_options = "Mude opções para o servidor.",
	menu_desc_spectate_off = "You'll automatically join the action when an opening is available.",
	menu_desc_spectate_on = "Você vai ficar no modo de espectador.",
	menu_desc_preferences = "Mudar opções para você mesmo. Elas não afetam outros jogadores.",
	menu_desc_records = "Visualizar suas pontuações máximas.",
	menu_desc_djui_menu = "Entrar no menu DJUI. You can also press the R button to access this.",
	menu_desc_quit_practice = "Sair da pratica.",

	menu_title_confirm = "Confirmar?",
	menu_desc_confirm_restart = "Você tem certeza que deseja reiniciar? Qualquer progresso que não está salvo vai ser perdido!",
	menu_desc_confirm_quit = "Você tem certeza que deseja sair? Qualquer progresso que não está salvo vai ser perdido!",
	menu_desc_confirm_practice = "Você tem certeza de que deseja entrar no nível de tutorial? Você será removido do nível atual!",

	menu_desc_grab_button = "Use this button to place/pick up ingredients. Takes priority over the button's normal action.",
	menu_desc_action_button = "Use this button to chop ingredients and wash dishes.\nNote that using B will cause these actions to take priority over grabbing.",
	menu_desc_throw_button = "Use this button to throw ingredients.\nNote that grabbing/placing takes priority if using B.",
	menu_desc_reduced_motion = "Desativa partes em movimento do menu.",
	menu_desc_order_left = "Pedidos aparecem do lado esquerdo da tela.",
	menu_desc_order_right = "Pedidos aparecem do lado direito da tela.",
	menu_desc_order_left_offset = "Orders appear on the left side of the screen, shifted right so the FPS counter doesn't cover them.",
	menu_desc_order_right_offset = "Orders appear on the right side of the screen, shifted left so the popups don't cover them.",
	menu_desc_left_to_right = "The oldest order will be on the left side of the queue. Serve left to right to maintain the tip combo.",
	menu_desc_right_to_left = "The oldest order will be on the right side of the queue. Serve right to left to maintain the tip combo.",
	menu_desc_cook_indicators = "Show a graphic above the timer whenever something is done cooking or is burning. Useful if you can't rely on audio queues.",
	menu_desc_language = "Selecione a linguagem para esse mod.\n\n(Recado: Not all languages supported by sm64coopdx are supported.)",
	menu_desc_disable_water_effect = "Desativa a água em movimento em um dos níveis.",

	menu_title_join = "Entrar?",
	menu_desc_join_now = "Join the action right now, or until a spot opens up.",
	menu_desc_join_wait = "Start playing as soon as this level is over.",
	menu_desc_join_practice = "Enter the tutorial area to practice.",
	menu_desc_join_spectate = "Become a spectator until you disable spectating in the pause menu.",

	menu_desc_records_players_overall = "View the overall best records.",
	menu_desc_records_players_solo = "View records for solo play.",
	menu_desc_records_players = "View records for %d players.",

	menu_desc_auto_start_off = "Comece o jogo por si só.",
	menu_desc_auto_start_on = "O jogo vai automaticamente progredir para o próximo nível.",
	menu_desc_mid_game_join_off = "Anyone who joins mid-game will have to wait until the next level.",
	menu_desc_mid_game_join_on = "Jogadores podem entrar enquanto um nível está em progresso.",
}