🧠 Nível Mestre: Missões e Modularização Total

🎯 Objetivo
Evoluir o jogo War para uma versão completa e modularizada:
Dividir o código em funções bem definidas para melhor organização e manutenção.
Implementar um sistema de missões aleatórias para o jogador.
Verificar o cumprimento da missão e declarar vitória.
Aplicar boas práticas como uso de const para leitura de dados, modularização total, passagem por referência e gerenciamento de memória.

🆕 Novidades em relação ao Nível Aventureiro
Inicialização automática dos territórios (sem cadastro manual).
Missões aleatórias:
Destruir o exército Verde.
Conquistar 3 territórios.
Menu interativo com opções para atacar, verificar missão ou sair.
Verificação automática de vitória ao cumprir a missão.

⚙️ Funcionalidades
Alocação dinâmica do mapa com calloc e liberação com free.
Inicialização pré-definida de 5 territórios com nomes, cores e tropas iniciais.
Simulação de ataques com dados aleatórios (1 dado por lado, empate favorece atacante).
Atualização do mapa após batalhas, incluindo conquistas.
Menu principal:
1: Atacar (escolher território atacante e defensor).
2: Verificar Missão (checa se cumprida e declara vitória se sim).
0: Sair.
Exibição do mapa e da missão a cada rodada.
Validações para ataques (ex: atacante deve ser do jogador e ter tropas suficientes).

💡 Conceitos abordados
Modularização total: Funções separadas para alocação, inicialização, exibição, ataques, missões e verificações.
const correctness para funções de leitura (ex: exibirMapa, verificarVitoria).
Ponteiros e passagem por referência para modificações.
Aleatoriedade com rand() e srand(time(NULL)).
Lógica de jogo: Batalhas, conquistas e condições de vitória.
Função utilitária para limpar buffer de entrada.

📥 Entrada
Escolha no menu (1, 2 ou 0).
Para ataques: Números dos territórios atacante e defensor (1 a 5).

📤 Saída
Mapa atualizado com territórios, cores e tropas.
Descrição da missão atual.
Resultados de batalhas (dados rolados, tropas perdidas, conquistas).
Mensagem de verificação da missão (cumprida ou não).
Mensagem de vitória ao cumprir a missão.

📝 Observações
O jogador controla o exército "Azul" e inicia com 2 territórios.
Ataques só são permitidos de territórios próprios com pelo menos 2 tropas para o atacante.
Defensores não podem ser territórios próprios.
Missões são sorteadas aleatoriamente no início.
Executar em terminal interativo para melhor experiência.
Use system ("pause") ou similar se precisar pausar em ambientes Windows (não incluído no código para portabilidade).
