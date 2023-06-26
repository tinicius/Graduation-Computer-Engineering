# Trabalho PROG II

## Introdução

### Trabalho para a disciplina de Programação de Computadores II

Foi solicitado o desenvolvimento de uma aplicação em C++ para resolver o seguinte problema:

```cpp
"Um médico solicitou a criação de um sistema para o seu consultório. A ideia é que o
sistema permita armazenar os dados do consultório, paciente, médicos (já que mais de
um médico irá atender no mesmo consultório) e as consultas marcadas. Após uma
reunião com o analista de sistemas responsável, foi proposto o desenvolvimento do
sistema representado pelo esboço do diagrama de classes abaixo. Ao iniciar o
desenvolvimento do sistema o analista responsável percebeu que o Diagrama precisava
de alguns ajustes. Faça os ajustes no diagrama de classes e implemente o sistema."
```

![Untitled](Trabalho%20PROG%20II%201423707b9a6047369709c1a2fdb6b663/Untitled.png)

## Decisões de Implementação

- Consultório
    - Cada programa poderá armazenar os dados de apenas um consultório, sendo possível configurar os dados desse.
    - O consultório fica aberto de 08:00 às 18:00 de seg a sex (ainda não é possível alterar esse valor)
    - As consultas são marcadas de hora em hora
    - Dados para configurar: nomes, endereço e telefone
- Médico
    - O programa não limita o número de médicos
    - O CPF  e o CRM do médico é validado na hora do cadastro
    - Ao remover um médico, todas suas consultas também são removidas
    - Dados para cadastrar: CRM, especialidade, nome, endereço, CPF, telefone, sexo
    - Imprimindo:
    
    ```jsx
    Nome Sobrenome, M, Rua, 11111111111, 37 2112-1221
    ```
    
- Paciente
    - O programa não limite o número de pacientes
    - O CPF é validade na hora do cadastro
    - O campo medicação se refere a medicamentos que o paciente está utilizando no momento ou de maneira contínua
    - Ao remover um paciente, todas suas consultas também são removidas
    - Dados para cadastrar: nome, endereço, CPF, telefone, sexo, relato, medicação
    - Imprimindo:
    
    ```jsx
    Nome Sobrenome, M, Rua, 11111111111, 37 3333-2222
    ```
    
- Consulta
    - O programa não limite o número de consultas
    - O proprio usuário escolhe o médico, a partir de uma lista que é exibida, digitando o CRM
    - É verificado se o paciente já está cadastrado pelo CPF
    - É verificado se o médico já está cadastrado pelo CRM
    - A consulta é automaticamente marcada para o próximo horário disponível
    - A consulta não é marcada fora do horário de funcionamento do consultório
    - Cada consulta tem um id numérico único
    - Dados para cadastrar: CPF, CRM (do médico escolhido)
    - Imprimindo:
    
    ```jsx
    [1] Paciente: Nome Sobrenome, Relato: relato, Medicacão: medicação
    Doutor: Nome Sobrenome, Especilidade, CRM: 123456
    Data: 12/10/2022 9:0
    ```
    

## Diagrama de Classes

![Trabalho PROG II.drawio.png](Trabalho%20PROG%20II%201423707b9a6047369709c1a2fdb6b663/Trabalho_PROG_II.drawio.png)

## Casos de Teste

Os seguindo casos de testes buscam verificar as funcionalidades já desenvolvidas e citadas nas “Decisões de Implementação”.

1. Consultório
    1. Cadastrando consultório corretamente
2. Médico
    1. Cadastrando médico corretamente
    2. Cadastrando médico com CRM repetido
    3. Cadastrando médico com CPF repetido
    4. Imprimindo dados do médico
    5. Removendo um médico
    6. Removendo um médico, não havendo nenhum médico cadastrado
3. Paciente
    1. Cadastrando paciente corretamente
    2. Cadastrando paciente com CPF repetido
    3. Imprimindo dados do paciente
    4. Removendo um paciente
    5. Removendo um paciente, não havendo nenhum paciente cadastrado
4. Consultas
    1. Cadastrando uma consulta corretamente
    2. Imprimindo todas consultas
    3. Imprimindo dados de uma consulta em específico
    4. Removendo uma consulta
    5. Removendo uma consulta, não havendo nenhuma consulta cadastrada

## Resultados dos Testes

1. Consultório
    
    Cadastrando consultório corretamente
    
    ```cpp
    Seja bem-vindo ao sistema do nosso consultório
    Pressione qualquer tecla para continuar...
    Digite o nome do consultório: Clinica Xulambs
    Digite o endereco do consultorio: Rua xulambs
    Digite o telefone do consultorio: 37 3211-2441
    ```
    
2. Médico
    
    Cadastrando médico corretamente
    
    ```cpp
    Digite uma opção: 1
    Digite o CRM: 123456
    Digite a especialidade: Cardiologista
    Digite o nome: Junior
    Digite o endereço: Rua a, Bairro b, Número 2
    Digite o CPF: 11122233344
    Digite o telefone: 37 991222-2121
    Digite o sexo (M ou F): M
    Médico cadastrado com sucesso!
    Pressione qualquer tecla para continuar...
    ```
    
    Cadastrando médico com CRM repetido
    
    ```cpp
    Digite uma opção: 1
    Digite o CRM: 123456
    Digite a especialidade: Dentista
    Digite o nome: Pedro
    Digite o endereço: Rua c
    Digite o CPF: 12332112323
    Digite o telefone: 37 14141-1414
    Digite o sexo (M ou F): M
    CRM já utilizado!
    Pressione qualquer tecla para continuar...
    ```
    
    Cadastrando médico com CPF repetido
    
    ```cpp
    Digite uma opção: 1
    Digite o CRM: 123221
    Digite a especialidade: Otorrino
    Digite o nome: Jorge
    Digite o endereço: Rua Castro Alves, 2341
    Digite o CPF: 11122233344
    Digite o telefone: 38 3212-1221
    Digite o sexo (M ou F): M
    CPF já utilizado!
    Pressione qualquer tecla para continuar...
    ```
    
    Imprimindo dados do médico
    
    ```cpp
    Digite uma opção: 4
    Digite o cpf do médico: 11122233344
    Junior, M, Rua a, Bairro b, Número 2, 11122233344, 37 991222-2121
    Pressione qualquer tecla para continuar...
    ```
    
    Removendo um médico
    
    ```cpp
    Digite uma opção: 8
    Digite o CPF do médico que deseja remover: 11122233344
    Médico removido com sucesso!
    Pressione qualquer tecla para continuar...
    ```
    
    Removendo um médico, não havendo nenhum médico cadastrado
    
    ```cpp
    Digite uma opção: 8
    Digite o CPF do médico que deseja remover: 123123123
    Médico não cadastrado!
    Pressione qualquer tecla para continuar...
    ```
    
3. Paciente
    
    Cadastrando paciente corretamente
    
    ```cpp
    Digite uma opção: 2
    Digite o nome: Vinicius Alves
    Digite o endereço: Rua T, Bela Vista, 1234
    Digite o CPF: 33344455566
    Digite o telefone: 37 3232-1212
    Digite o sexo (M ou F): M
    Digite o relato: o CEFET está me matando :(
    Digite a medicacao: nenhuma
    Paciente cadastrado com sucesso!
    Pressione qualquer tecla para continuar...
    ```
    
    Cadastrando paciente com CPF repetido
    
    ```cpp
    Digite uma opção: 2
    Digite o nome: Lucas
    Digite o endereço: Rua v
    Digite o CPF: 33344455566
    Digite o telefone: 37 3232-1221
    Digite o sexo (M ou F): M
    Digite o relato: dor nas costas
    Digite a medicacao: dipirona
    CPF já utilizado!
    Pressione qualquer tecla para continuar...
    ```
    
    Imprimindo dados do paciente
    
    ```cpp
    Digite uma opção: 6
    Digite o CPF do paciente: 33344455566
    Vinicius Alves, M, Rua T, Bela Vista, 1234, 33344455566, 37 3232-1212
    Pressione qualquer tecla para continuar...
    ```
    
    Removendo um paciente
    
    ```cpp
    Digite uma opção: 9
    Digite o CPF do paciente que deseja remover: 33344455566
    Paciente removido com sucesso!
    Pressione qualquer tecla para continuar...
    ```
    
    Removendo um paciente, não havendo nenhum paciente cadastrado
    
    ```cpp
    Digite uma opção: 9
    Digite o CPF do paciente que deseja remover: 123
    Paciente não cadastrado!
    Pressione qualquer tecla para continuar...
    ```
    
4. Consultas
    
    Cadastrando uma consulta corretamente
    
    ```cpp
    Digite uma opção: 3
    Digite o CPF do paciente: 11223312312
    Doutor Jorge, Cardio, CRM: 123456
    Digite o CRM do médico escolhido: 123456
    Consulta cadastrada com sucesso!
    Pressione qualquer tecla para continuar...
    ```
    
    Cadastrando consulta sem médicos cadastrados
    
    ```cpp
    Digite uma opção: 3
    Digite o CPF do paciente: 09321233212
    Digite o CRM do médico escolhido: 123321
    Paciente não cadastrado!
    Pressione qualquer tecla para continuar...
    ```
    
    Cadastrando consultas sem pacientes cadastrado
    
    ```cpp
    Digite uma opção: 3
    Digite o CPF do paciente: 11122233344
    Doutor Jorge, Cardio, CRM: 123456
    Digite o CRM do médico escolhido: 123456
    Paciente não cadastrado!
    Pressione qualquer tecla para continuar...
    ```
    
    Imprimindo todas consultas
    
    ```cpp
    Digite uma opção: 5
    [2] Paciente: Vinicius, Relato: dor, Medicacão: nenhum
    Última consulta: 18/10/2022 15:0
    Doutor: Jorge, Cardio, CRM: 123456
    Data: 18/10/2022 16:0
    
    [1] Paciente: Vinicius, Relato: dor, Medicacão: nenhum
    Doutor: Jorge, Cardio, CRM: 123456
    Data: 18/10/2022 15:0
    
    Pressione qualquer tecla para continuar...
    ```
    
    Imprimindo consultas sem consultas cadastradas
    
    ```cpp
    Digite uma opção: 5
    Nenhuma consulta cadastrada!
    Pressione qualquer tecla para continuar...
    ```
    
    Imprimindo dados de uma consulta em específico (todas consultas com mesmo médico e paciente)
    
    ```cpp
    Digite uma opção: 7
    Digite o CPF do paciente: 11223312312
    Digite o CPF do médico: 123456
    [2] Paciente: Vinicius, Relato: dor, Medicacão: nenhum
    Última consulta: 18/10/2022 15:0
    Doutor: Jorge, Cardio, CRM: 123456
    Data: 18/10/2022 16:0
    
    [1] Paciente: Vinicius, Relato: dor, Medicacão: nenhum
    Doutor: Jorge, Cardio, CRM: 123456
    Data: 18/10/2022 15:0
    
    Pressione qualquer tecla para continuar...
    ```
    
    Removendo uma consulta
    
    ```cpp
    Digite uma opção: 10
    [1] Paciente: Paciente, Relato: dor, Medicacão: dipirona
    Doutor: Lucas, CArdio, CRM: 123456
    Data: 18/10/2022 15:0
    
    Digite o número da consulta que deseja remover:1
    Consulta removida com sucesso!
    ```
    
    Removendo uma consulta, não havendo nenhuma consulta cadastrada
    
    ```cpp
    Digite uma opção: 10
    Nenhuma consulta cadastrada!
    Pressione qualquer tecla para continuar...
    ```
    

## Análise dos resultados

A aplicação apresenta todas as funcionalidades solicitadas funcionando de maneira correta. Porém ainda a espaço diversas funcionalidades e existem algumas correções que precisam ser desenvolvidas para evitar possíveis bugs no futuro.

Em muitos campos onde é solicitada a entrada do usuário os dados não são validados. Existem validações que precisam ser adicionadas como mínimo de caracteres, validação de CPF, validação do número de telefone, entre outras.

Existem algumas mudanças de interface que podem ser feitas para melhorar o percurso do usuário. Exemplos, ler o campo de “relato” no momento da criação de uma consulta, e não ao adiocionar o usuário ao sistema.