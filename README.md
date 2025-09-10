# 🧩 Nível Novato: Cadastro Inicial dos Territórios

## 🎯 Objetivo
Cadastrar territórios do jogo War e exibir o mapa atual.  
Cada território possui: **Nome**, **Cor do Exército** e **Número de Tropas**.

## ⚙️ Funcionalidades
- Entrada de dados pelo terminal 🖥️  
- Armazenamento em vetor estático de 5 territórios 📦  
- Impressão organizada do estado do mapa 🗺️

## 💡 Conceitos abordados
- `struct` para representar cada território  
- Vetores estáticos  
- Entrada/saída com `scanf`, `fgets` e `printf`  
- Manipulação de strings para remover `\n`  

## 📥 Entrada
O usuário informa, para cada território:  
- Nome do território 🏞️  
- Cor do exército 🎨  
- Quantidade de tropas ⚔️  

## 📤 Saída
Após o cadastro, o programa exibe o **estado atual do mapa**

## 📝 Observações
- Limite de caracteres: Nome até 30, Cor até 10  
- Executar em terminal interativo  
- Remove automaticamente o `\n` do `fgets` para exibição correta
