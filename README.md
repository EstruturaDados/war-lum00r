# 🧩 Nível Aventureiro: Mapa Dinâmico e Modularização

## 🎯 Objetivo

Evoluir o cadastro de territórios do jogo War:

* Modularizar o código em funções especializadas.
* Substituir vetor fixo por **memória dinâmica**.
* Criar um **menu interativo** para o jogador.

## ⚙️ Funcionalidades

* Definição de `struct Territorio` com nome, cor e tropas.
* **Alocação dinâmica** (`malloc` / `free`) para o mapa.
* **Cadastro** de territórios via terminal 🖥️.
* **Exibição** do estado atual do mapa 🗺️.
* **Menu de opções**:

  * 1️⃣ Cadastrar territórios
  * 2️⃣ Exibir mapa
  * 0️⃣ Sair

## 📚 Conceitos abordados

* Modularização: separação em funções (`alocarMapa`, `cadastrarTerritorios`, `exibirMapa`, `liberarMapa`).
* Ponteiros e passagem por referência.
* Memória dinâmica (`malloc`, `free`).
* `const` para funções que apenas leem dados.
* Função utilitária `limparBufferEntrada`.

## 📥 Entrada

* Quantidade de territórios a ser cadastrada.
* Para cada território:

  * Nome 🏞️ (até 30 caracteres)
  * Cor 🎨 (até 10 caracteres)
  * Tropas ⚔️ (inteiro positivo)

## 📤 Saída 

Exibição organizada de todos os territórios cadastrados:

* Nome
* Cor do Exército
* Tropas
