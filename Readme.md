# Projeto Alterando Taxa LED com Interrupções

## Pré-requisitos

- Raspberry Pi Pico W
- SDK do Pico configurado
- Ferramentas de compilação (CMake, Ninja, etc.)
- 1 LED
- 2 Botões

## Como Usar

1. Clone o repositório:

    ```sh
    git clone <URL_DO_REPOSITORIO>
    cd <NOME_DO_REPOSITORIO>
    ```

2. Compile o código:

    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Pegue o arquivo `.uf2` gerado na pasta `build` e copie para a placa Pico W.

4. Teste o funcionamento na placa.

## Funcionamento

- O LED conectado ao pino 11 pisca com uma taxa inicial de 1000 ms.
- Pressione o botão conectado ao pino 5 (BTA) para aumentar a taxa em 100 ms.
- Pressione o botão conectado ao pino 6 (BTB) para diminuir a taxa em 100 ms.