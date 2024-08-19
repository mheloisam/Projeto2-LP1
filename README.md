# Sistema Controlador de Viagens

## 1. Compilação e Execução:
### Compilação
#### Abra o Prompt de Comando ou Windows Terminal
g++ -o sistema_viagens.exe main.cpp cidade.cpp trajeto.cpp transporte.cpp passageiro.cpp viagem.cpp controlador_de_transito.cpp
### Execução
#### Após a compilação, execute o programa com:
sistema_viagens.exe

## 2. O que foi implementado:
#### Cadastro de Cidades
#### Cadastro de Trajetos
#### Cadastro de Transportes
#### Cadastro de Passageiros
#### Gestão de Viagens:
####  - Iniciar viagem entre cidades
####  - Escolher o transporte e passageiros
####  - Verificar se o transporte está na cidade de origem
####  - Registrar a partida do transporte
####  - Avançar horas e atualizar estado do sistema
####  - Registrar chegada do transporte na cidade de destino
####  - Calcular o melhor trajeto entre cidades
#### Consultas e Relatórios:
####  - Relatar onde estão cada pessoa (cidade ou em trânsito, informando origem-destino-transporte)
####  - Relatar onde está cada transporte (cidade ou em trânsito)
####  - Relatar todas as viagens em andamento

## 3. O que não foi implementado:
#### Persistência de dados: Os dados não são salvos em arquivos e serão perdidos quando o programa for encerrado.
#### Gestão de viagens:
####  - A implementação para calcular o melhor trajeto considerando conexões intermediárias (viagens conectadas) não está completa.
####  - A lógica para criar e gerenciar múltiplas viagens conectadas e garantir que todas sejam concluídas antes de mover passageiros e transportes para o destino final não está totalmente implementada.
#### Consultas e Relatórios:
####  - Relatar as cidades mais visitadas
####  - Implementar consulta de viagens com conexão




