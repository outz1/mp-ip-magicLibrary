# 🧙 Guia de Git para o Projeto — Biblioteca Mágica

> Guia prático para quem nunca usou Git, com o fluxo de trabalho adaptado ao roadmap do projeto.

---

## 📋 Índice

1. [O que é Git e por que usar](#1-o-que-é-git-e-por-que-usar)
2. [Instalação e configuração inicial](#2-instalação-e-configuração-inicial)
3. [Conceitos fundamentais](#3-conceitos-fundamentais)
4. [Configurando o repositório do projeto](#4-configurando-o-repositório-do-projeto)
5. [Fluxo de trabalho diário](#5-fluxo-de-trabalho-diário)
6. [Seguindo o Roadmap com branches](#6-seguindo-o-roadmap-com-branches)
7. [Atualizando o Roadmap e sincronizando a equipe](#7-atualizando-o-roadmap-e-sincronizando-a-equipe)
8. [Resolvendo conflitos](#8-resolvendo-conflitos)
9. [Cheatsheet — Referência rápida](#9-cheatsheet--referência-rápida)
10. [Checklist diário](#10-checklist-diário)

---

## 1. O que é Git e por que usar

### O problema sem Git

Imagine 4 pessoas editando o mesmo arquivo `main.c` e se mandando versões por WhatsApp:
- `main_FINAL.c`
- `main_FINAL_v2.c`
- `main_AGORA_VAI.c`
- `main_REAL_FINAL.c` ← qual é a certa?

Isso é caos. **Git resolve isso.**

### O que é Git

**Git** é um sistema de controle de versão. Ele:
- Salva um **histórico completo** de todas as alterações feitas no código
- Permite que **múltiplas pessoas** trabalhem ao mesmo tempo sem sobrescrever o trabalho umas das outras
- Permite **voltar no tempo** para qualquer versão anterior do código
- Facilita a **integração** do trabalho de cada pessoa

### O que é GitHub

**GitHub** é um site que hospeda repositórios Git na nuvem. Pense nele como um Google Drive para código, com superpoderes de colaboração.

```
Seu computador (Git local) ←→ GitHub (repositório remoto)
```

---

## 2. Instalação e configuração inicial

### Instalar o Git

**Windows:**
```
https://git-scm.com/download/win
```
Baixe e instale. Durante a instalação, deixe todas as opções padrão.

**Linux (Ubuntu/Debian):**
```bash
sudo apt update
sudo apt install git
```

**Linux (Fedora):**
```bash
sudo dnf install git
```

**macOS:**
```bash
brew install git
```

### Verificar instalação

```bash
git --version
# Saída esperada: git version 2.x.x
```

### Configuração obrigatória (fazer uma vez só)

Antes de qualquer coisa, diga ao Git quem você é. Esses dados aparecem em cada commit que você fizer:

```bash
git config --global user.name "Seu Nome Aqui"
git config --global user.email "seu@email.com"
```

**Configuração de editor (opcional, mas recomendado):**
```bash
# Para usar o VS Code como editor padrão do Git
git config --global core.editor "code --wait"

# Para usar o nano (mais simples no terminal)
git config --global core.editor "nano"
```

**Verificar suas configurações:**
```bash
git config --list
```

---

## 3. Conceitos fundamentais

### 3.1 Repositório (repo)

É a pasta do projeto rastreada pelo Git. Contém todo o código **mais** o histórico completo de alterações.

```
biblioteca-magica/     ← esta pasta toda é o repositório
├── .git/              ← pasta oculta onde o Git guarda o histórico (não mexa!)
├── main.c
├── README.md
└── ...
```

### 3.2 Commit

Um **commit** é como um "save game" do código. Cada commit é um ponto no histórico ao qual você pode retornar.

```
Histórico de commits:
○  [hoje]     "feat: adiciona função listarTitulos"
○  [ontem]    "feat: adiciona função mostrarLivro"
○  [semana passada]  "feat: implementa estrutura inicial das structs"
```

> **Regra de ouro:** commit cedo, commit frequente. Cada funcionalidade concluída = 1 commit.

### 3.3 Branch (ramo)

Uma **branch** é uma linha paralela de desenvolvimento. Pense assim:

```
main ──────────────────────────────────────→  (código estável, funcional)
         │
         └── feat/cadastrar-livro ────────→  (Dev 1 trabalhando aqui)
         │
         └── feat/mostrar-livro ──────────→  (Dev 2 trabalhando aqui)
```

Cada desenvolvedor trabalha na **sua própria branch** sem afetar o código dos outros. Quando a funcionalidade está pronta, a branch é **mesclada** de volta à `main`.

### 3.4 Merge (mesclagem)

É a operação que une o trabalho de uma branch de volta à branch principal:

```
main ────────────────────────────────────→
         │                         ↑
         └── feat/cadastrar-livro ─┘
              (pronto! merge feito)
```

### 3.5 Push e Pull

```
git push  →  Envia seus commits locais para o GitHub
git pull  →  Baixa os commits do GitHub para seu computador
```

Regra simples:
- **Antes de começar a trabalhar:** `git pull` (baixar o que outros fizeram)
- **Depois de terminar:** `git push` (enviar o que você fez)

---

## 4. Configurando o repositório do projeto

### Passo 1 — Criar o repositório no GitHub (Dev 1 faz isso)

1. Acesse [github.com](https://github.com) e faça login
2. Clique no botão **"New"** (ou **"+"** → **"New repository"**)
3. Preencha:
   - **Repository name:** `biblioteca-magica`
   - **Description:** `Mini Projeto 03 - Backend de Jogo: Biblioteca Mágica`
   - Marque **"Public"**
   - Marque **"Add a README file"**
4. Clique em **"Create repository"**

### Passo 2 — Clonar o repositório (todos os membros fazem isso)

```bash
# Substitua SEU_USUARIO pelo nome de usuário do GitHub do Dev 1
git clone https://github.com/SEU_USUARIO/biblioteca-magica.git

# Entre na pasta do projeto
cd biblioteca-magica
```

### Passo 3 — Proteger a branch main (Dev 1 faz no GitHub)

Para evitar que alguém suba código quebrado diretamente na `main`:

1. No repositório, vá em **Settings** → **Branches**
2. Clique em **"Add branch ruleset"** (ou "Add rule" dependendo da versão)
3. Em **"Branch name pattern"**, coloque: `main`
4. Marque **"Require a pull request before merging"**
5. Clique em **"Create"**

> Agora ninguém consegue fazer `push` diretamente na `main`. Todo código precisa passar por um Pull Request (PR).

### Passo 4 — Adicionar os membros como colaboradores (Dev 1 faz)

1. No repositório, vá em **Settings** → **Collaborators**
2. Clique em **"Add people"**
3. Adicione os usuários do GitHub dos outros 3 membros

### Passo 5 — Aceitar o convite (Devs 2, 3 e 4)

Cada membro receberá um e-mail do GitHub com um convite. Clique em **"Accept invitation"**.

---

## 5. Fluxo de trabalho diário

Este é o ciclo que cada desenvolvedor deve seguir **todo dia** de trabalho.

### Visão geral do ciclo

```
1. git pull          ← atualizar com o que o time fez
2. git checkout -b   ← criar/entrar na sua branch
3. [editar código]   ← trabalhar
4. git add           ← selecionar o que vai no commit
5. git commit        ← salvar o ponto do histórico
6. git push          ← enviar para o GitHub
7. Pull Request      ← pedir para mesclar na main
```

---

### 5.1 Atualizar seu repositório local

**Sempre faça isso antes de começar a trabalhar:**

```bash
# Ir para a branch principal
git checkout main

# Baixar o que o time fez
git pull origin main
```

---

### 5.2 Criar sua branch de trabalho

Cada funcionalidade tem sua própria branch. Use nomes descritivos:

```bash
# Formato: tipo/o-que-faz
git checkout -b feat/cadastrar-livro
git checkout -b feat/mostrar-livro
git checkout -b feat/deletar-livro
git checkout -b feat/criptografia
git checkout -b fix/bug-no-menu
git checkout -b docs/atualiza-roadmap
```

**Verificar em qual branch você está:**
```bash
git branch
# O asterisco (*) indica a branch atual
#   main
# * feat/cadastrar-livro
```

---

### 5.3 Adicionar e commitar alterações

Depois de editar o código:

```bash
# Ver quais arquivos foram modificados
git status

# Adicionar um arquivo específico ao próximo commit
git add main.c

# Adicionar todos os arquivos modificados de uma vez
git add .

# Criar o commit com uma mensagem descritiva
git commit -m "feat: implementa funcao cadastrarLivro com alocacao dinamica"
```

#### Boas práticas de mensagem de commit

Use o formato: `tipo: descrição curta do que foi feito`

| Tipo | Quando usar | Exemplo |
|---|---|---|
| `feat` | Nova funcionalidade | `feat: adiciona funcao listarTitulos` |
| `fix` | Correção de bug | `fix: corrige vazamento de memoria em deletarLivro` |
| `docs` | Documentação | `docs: atualiza roadmap no README` |
| `refactor` | Melhoria sem nova feature | `refactor: reorganiza menu em funcao separada` |
| `test` | Testes | `test: adiciona casos de teste para criptografar` |
| `chore` | Tarefas diversas | `chore: adiciona .gitignore` |

---

### 5.4 Enviar para o GitHub

```bash
# Enviar a branch para o GitHub
# Na primeira vez em uma branch nova:
git push -u origin feat/cadastrar-livro

# Nas próximas vezes (na mesma branch):
git push
```

---

### 5.5 Abrir um Pull Request (PR)

1. Acesse o repositório no GitHub
2. Aparecerá um banner amarelo: **"Compare & pull request"** — clique nele
3. Preencha:
   - **Título:** `feat: implementa cadastrarLivro`
   - **Descrição:** explique o que foi feito, como testar, etc.
4. Clique em **"Create pull request"**
5. Avise o time no grupo para revisar e aprovar

---

### 5.6 Revisar e aprovar um PR

1. Abra o PR no GitHub
2. Vá na aba **"Files changed"** para ver o que mudou
3. Se estiver tudo certo, clique em **"Review changes"** → **"Approve"** → **"Submit review"**
4. O autor do PR clica em **"Merge pull request"**

> **Dica:** o Dev 1 (responsável pelo repositório) pode habilitar a opção de que apenas 1 aprovação já é suficiente para merge.

---

## 6. Seguindo o Roadmap com branches

O roadmap está dividido em 4 fases. Veja como cada fase mapeia para branches no Git:

### Fase 1 — Estrutura Base (Dev 1)

```bash
# Dev 1 cria a estrutura inicial
git checkout main
git pull origin main
git checkout -b fase1/estrutura-base

# Criar os arquivos:
# structs.h, main.c (com menu e argv), biblioteca.h

git add .
git commit -m "feat: define structs Data, Autor e LivroMagico"

git add main.c
git commit -m "feat: implementa main com menu loop e validacao de argv"

git push -u origin fase1/estrutura-base
# → Abre PR → time revisa → merge na main
```

### Fase 2 — CRUD (Devs 1 e 2, em paralelo)

```bash
# Dev 1 — após merge da Fase 1
git checkout main && git pull
git checkout -b feat/cadastrar-livro
# ... trabalha ...
git commit -m "feat: implementa cadastrarLivro com malloc e id unico"
git push -u origin feat/cadastrar-livro

# Dev 2 — ao mesmo tempo
git checkout main && git pull
git checkout -b feat/visualizacao
# ... trabalha mostrarLivro, editarLivro, listarTitulos ...
git commit -m "feat: implementa mostrarLivro e listarTitulos"
git commit -m "feat: implementa editarLivro campo a campo"
git push -u origin feat/visualizacao
```

### Fase 3 — Persistência (Dev 3)

```bash
git checkout main && git pull
git checkout -b feat/persistencia-arquivo

git commit -m "feat: implementa deletarLivro com free e reset do slot"
git commit -m "feat: implementa salvarBiblioteca com criptografia de titulo"
git commit -m "feat: implementa carregarBiblioteca com alocacao dinamica"

git push -u origin feat/persistencia-arquivo
```

### Fase 4 — Criptografia e Extras (Dev 4)

```bash
git checkout main && git pull
git checkout -b feat/criptografia

git commit -m "feat: implementa criptografar e descriptografar (complemento 255)"
git commit -m "feat: adiciona confirmacao antes de deletar livro"
git commit -m "feat: adiciona coloracao ANSI no menu"

git push -u origin feat/criptografia
```

### Diagrama de branches ao longo do tempo

```
main ──────────●────────────────●──────────────●────────────────────●→
               │  (merge fase1) │  (merge crud) │ (merge persistência)│(merge cripto)
               │                │               │                     │
fase1/estrutura-base ──●         │               │                     │
                                 │               │                     │
                    feat/cadastrar-livro ─────●  │                     │
                    feat/visualizacao ────────●  │                     │
                                                  feat/persistencia ──● │
                                                                        feat/criptografia ──●
```

---

## 7. Atualizando o Roadmap e sincronizando a equipe

O `README.md` contém o Roadmap em formato Mermaid Gantt. Ele deve ser atualizado conforme o projeto avança para refletir o estado real.

### 7.1 Quem atualiza o Roadmap

**Dev 4** é o responsável pelo `README.md`, mas **qualquer membro** pode e deve propor atualizações via PR.

### 7.2 Como atualizar o status de uma tarefa no Gantt

Abra o `README.md` e localize o bloco do Gantt. As tarefas podem ter três estados:

| Status no Gantt | Significado |
|---|---|
| ` ` (sem marcador) | Não iniciada (padrão) |
| `active,` | Em andamento |
| `done,` | Concluída |
| `crit,` | Crítica / prazo apertado |

**Exemplo — tarefa NÃO iniciada:**
```
Implementar cadastrarLivro  :         f2a, after f1c, 2d
```

**Exemplo — tarefa EM ANDAMENTO:**
```
Implementar cadastrarLivro  :active,  f2a, after f1c, 2d
```

**Exemplo — tarefa CONCLUÍDA:**
```
Implementar cadastrarLivro  :done,    f2a, after f1c, 2d
```

### 7.3 Fluxo completo para atualizar o Roadmap

```bash
# 1. Garantir que você tem a versão mais recente da main
git checkout main
git pull origin main

# 2. Criar uma branch específica para a atualização
git checkout -b docs/atualiza-roadmap-fase2

# 3. Editar o README.md (marcar tarefas como done ou active)
# [edite o arquivo]

# 4. Commitar a atualização
git add README.md
git commit -m "docs: marca fase 1 como done e fase 2 como active no roadmap"

# 5. Enviar e abrir PR
git push -u origin docs/atualiza-roadmap-fase2
# → Abre PR no GitHub → merge rápido
```

### 7.4 Rotina de sincronização da equipe

Sugerimos um ritual simples de atualização, combinado no grupo:

#### A cada funcionalidade concluída (quem terminou):
```bash
git checkout main
git pull origin main
# Verificar se o PR foi mergeado com sucesso
```

#### Uma vez por dia (todos, antes de começar):
```bash
# Atualizar a main local
git checkout main
git pull origin main

# Atualizar sua branch com o que outros fizeram
git checkout feat/sua-branch
git merge main
# Se der conflito, ver Seção 8
```

#### A cada fim de fase (Dev 4 + todos revisam):
1. Todos os PRs da fase foram mergeados na `main`?
2. O código compila sem erros?
3. Atualizar o Roadmap no README marcando a fase como `done`

---

## 8. Resolvendo conflitos

Um **conflito** acontece quando dois membros editam a **mesma parte** do mesmo arquivo. O Git não sabe qual versão manter e pede sua ajuda.

### Quando acontece um conflito

```bash
git merge main
# CONFLICT (content): Merge conflict in main.c
# Automatic merge failed; fix conflicts and then commit the result.
```

### Como parece um conflito no arquivo

```c
<<<<<<< HEAD          ← o que VOCÊ tem
void mostrarLivro() {
    printf("Livro:\n");
=======               ← separador
void mostrarLivro() {
    printf("=== Livro ===\n");
>>>>>>> main          ← o que veio da main
```

### Como resolver

1. **Abra o arquivo** com conflito no editor
2. **Escolha** qual versão manter (ou combine as duas)
3. **Remova** as marcações `<<<<<<<`, `=======` e `>>>>>>>`
4. **Salve** o arquivo
5. **Finalize** o merge:

```bash
git add main.c
git commit -m "fix: resolve conflito em mostrarLivro"
```

### Evitando conflitos

A melhor estratégia é **dividir bem os arquivos** desde o início. Por isso o projeto tem arquivos separados (`biblioteca.c`, `arquivo.c`, `cripto.c`): cada Dev trabalha principalmente no seu arquivo, reduzindo conflitos ao mínimo.

```
Dev 1 → main.c, structs.h, biblioteca.c (cadastrarLivro)
Dev 2 → biblioteca.c (mostrarLivro, editarLivro, listarTitulos)
Dev 3 → arquivo.c (salvar, carregar, deletar)
Dev 4 → cripto.c, README.md
```

> **Se dois devs precisarem editar o mesmo arquivo:** combinem via grupo quem edita primeiro e quem faz `git pull` depois.

---

## 9. Cheatsheet — Referência rápida

```bash
# ─── CONFIGURAÇÃO ───────────────────────────────────────────────
git config --global user.name "Seu Nome"
git config --global user.email "seu@email.com"

# ─── COMEÇAR ────────────────────────────────────────────────────
git clone <url>                    # Clonar repositório
git init                           # Iniciar repo em pasta existente

# ─── STATUS E HISTÓRICO ─────────────────────────────────────────
git status                         # Ver o que mudou
git log                            # Ver histórico de commits
git log --oneline                  # Histórico compacto (1 linha por commit)
git diff                           # Ver as diferenças linha a linha

# ─── BRANCHES ───────────────────────────────────────────────────
git branch                         # Listar branches locais
git checkout -b feat/nome          # Criar e entrar em nova branch
git checkout main                  # Voltar para a main
git branch -d feat/nome            # Deletar branch (após merge)

# ─── SALVAR ALTERAÇÕES ──────────────────────────────────────────
git add arquivo.c                  # Adicionar arquivo específico
git add .                          # Adicionar tudo
git commit -m "mensagem"           # Commitar com mensagem

# ─── SINCRONIZAR COM GITHUB ─────────────────────────────────────
git pull origin main               # Baixar atualizações da main
git push -u origin feat/nome       # Enviar branch nova para o GitHub
git push                           # Enviar branch já configurada

# ─── MERGE E CONFLITOS ──────────────────────────────────────────
git merge main                     # Trazer mudanças da main para sua branch
git merge --abort                  # Cancelar um merge com conflito

# ─── DESFAZER COISAS ────────────────────────────────────────────
git restore arquivo.c              # Descartar mudanças não commitadas
git reset HEAD~1                   # Desfazer o último commit (mantém as edições)
git stash                          # Guardar mudanças temporariamente
git stash pop                      # Recuperar mudanças guardadas
```

---

## 10. Checklist diário

### ✅ Antes de começar a trabalhar

```
□ Entrei na branch main:         git checkout main
□ Atualizei a main:              git pull origin main
□ Entrei/criei minha branch:     git checkout -b feat/minha-tarefa
□ Atualizei minha branch:        git merge main
```

### ✅ Durante o trabalho

```
□ Commito com frequência (a cada funcionalidade pequena concluída)
□ Mensagens de commit são descritivas e seguem o padrão feat/fix/docs
□ Não edito arquivos que são responsabilidade de outro Dev sem combinar
□ Se tiver conflito, resolvo antes de continuar
```

### ✅ Ao terminar uma funcionalidade

```
□ Compilei o código e testei manualmente
□ Adicionei todos os arquivos:   git add .
□ Fiz o commit final:            git commit -m "feat: ..."
□ Enviei para o GitHub:          git push
□ Abri o Pull Request no GitHub
□ Avisei o time para revisar o PR
```

### ✅ Ao final de cada fase do Roadmap

```
□ Todos os PRs da fase foram mergeados
□ O código compila e funciona sem erros na main
□ Dev 4 atualizou o Roadmap no README.md (marcou fase como done)
□ PR do README foi mergeado
□ Time está alinhado sobre o que começa na próxima fase
```

---

## 🆘 Situações comuns e como resolver

| Situação | Solução |
|---|---|
| Fiz push na branch errada | `git revert HEAD` ou abra o PR apontando para a branch certa |
| Esqueci de criar uma branch e editei na main | `git stash` → `git checkout -b feat/nome` → `git stash pop` |
| Meu push foi rejeitado | Faça `git pull origin main` primeiro, resolva conflitos, depois `git push` |
| Quero ver o que outro Dev fez | `git fetch` → `git log origin/feat/branch-dele --oneline` |
| Deletei um arquivo sem querer | `git restore nome-do-arquivo.c` |
| O PR tem conflito e não deixa mergear | Faça `git merge main` na sua branch, resolva os conflitos, pushe novamente |

---

<div align="center">

*Para dúvidas sobre Git, a documentação oficial está em [git-scm.com/doc](https://git-scm.com/doc)*  
*Para dúvidas sobre GitHub, veja [docs.github.com](https://docs.github.com)*

</div>