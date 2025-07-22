## Requisitos e Responsabilidades do GitMaster

O GitMaster é responsável por garantir que o uso do Git e do GitHub no projeto seja padronizado, organizado e eficiente. As principais responsabilidades e requisitos são:

- **Padronizar o uso do Git e do GitHub entre os integrantes do grupo**, garantindo que todos utilizem as mesmas práticas e ferramentas.
- **Criar commits claros e descritivos**, explicando detalhadamente as alterações feitas no código, para facilitar o entendimento e o histórico do projeto.
- **Resolver conflitos de merge quando necessário**, sempre garantindo que o código esteja atualizado, funcional e que nenhuma alteração importante seja perdida.
- **Criar branches para novas funcionalidades ou correções de bugs**, permitindo que o desenvolvimento ocorra de forma isolada e segura, sem afetar a branch principal.
- **Criar tags para marcar versões importantes do projeto**, facilitando o acompanhamento do progresso, histórico de versões e a identificação rápida de possíveis problemas.
- **Zelar pela integridade do repositório**, garantindo que o código esteja sempre em um estado funcional e que as alterações sejam documentadas de forma adequada e clara.
- **Manter a documentação do projeto atualizada**, como o README.md e outras instruções necessárias para o uso e desenvolvimento do sistema.

Seguir essas práticas é fundamental para que o trabalho em equipe seja colaborativo, organizado e eficiente.

---

# Sistema de Autenticação com Hash de Senhas

## 1. Descrição do Problema a Ser Resolvido

Este projeto tem como objetivo desenvolver um sistema de autenticação simples e seguro, onde as senhas dos usuários são armazenadas utilizando hash com salt para evitar o armazenamento de senhas em texto puro. Isso ajuda a proteger as informações dos usuários contra acessos não autorizados.

---

## 2. Instruções para Compilar, Executar e Utilizar o Programa

### Requisitos
- Compilador C (GCC, Clang ou similar)
- Sistema operacional com terminal/linha de comando

### Passos para compilar

No terminal, na pasta do projeto, execute:

```bash
gcc -o sistema_autenticacao main.c
```

### Passos para executar

Execute o programa compilado:

```bash
./sistema_autenticacao
```

### Uso

O programa oferece um menu com as opções:

1. Cadastro — para criar um novo usuário com senha protegida.  
2. Login — para autenticar usuários cadastrados.  
3. Sair — para encerrar o programa.

---

## 3. Problemas Encontrados Durante o Desenvolvimento e Como Foram Resolvidos

- **Armazenamento seguro das senhas**: implementamos hash com salt para evitar senhas em texto puro.  
- **Prevenção de usuários duplicados**: verificamos no arquivo se o usuário já existia antes de cadastrar.  
- **Tratamento de entradas inválidas**: adicionamos validações e limpeza do buffer para evitar erros no menu.  
- **Conflitos no controle de versão**: utilizamos branches e merges com comunicação clara para evitar perda de código.

---

## 4. Responsabilidades do GitMaster no Projeto

O GitMaster desempenha papel fundamental para garantir que o projeto seja desenvolvido de forma colaborativa, organizada e eficiente. Para isso, ele deve:

- Criar branches para novas funcionalidades ou correções de bugs, permitindo que o trabalho seja feito de forma isolada e segura, sem impactar o código principal.  
- Criar tags para marcar versões importantes do projeto, facilitando o acompanhamento do progresso e a identificação de versões estáveis ou críticas.  
- Zelar pela integridade do repositório, garantindo que o código esteja sempre em um estado funcional e que as alterações sejam documentadas de forma adequada.  
- Padronizar o uso do Git e do GitHub entre os integrantes do grupo, definindo boas práticas para commits, merges e organização do repositório.  
- Criar commits claros e descritivos, explicando detalhadamente as alterações realizadas no código.  
- Resolver conflitos de merge quando necessário, assegurando que o código esteja sempre atualizado e funcionando corretamente.

Seguindo essas práticas, o GitMaster contribui para o sucesso do projeto e para o bom trabalho em equipe.

---

## 5. Contato e Colaboradores

- Nome do GitMaster: José Vinícius Silvestre Borges
- Outros integrantes: Kauan Alves
- Email para contato: viniciussborges.sb@gmail.com


