# 📚 Como Compilar e Executar a Biblioteca Mágica

> Guia rápido e direto para rodar o projeto em **Windows**, **Linux** e **macOS** — pule direto para o que você precisa.

---

## 🚦 Comece aqui: qual é a sua situação?

| Situação | Vá para |
|---|---|
| ✅ Já tenho GCC instalado e só quero compilar | [→ Compilar e Executar](#-compilar-e-executar-todos-os-sistemas) |
| ❌ Não tenho GCC / não sei se tenho | [→ Verificar e Instalar GCC](#-passo-1-verificar-e-instalar-o-gcc) |
| 🐧 Estou no Linux | [→ Seção Linux](#-linux-ubuntudebianfedora) |
| 🍎 Estou no macOS | [→ Seção macOS](#-macos) |
| 🪟 Estou no Windows | [→ Seção Windows](#-windows) |
| 🐛 Deu erro na compilação/execução | [→ Troubleshooting](#-troubleshooting) |
| 🎮 Já compilei, quero saber usar o programa | [→ Usando o Programa](#-usando-o-programa) |

---

## ✅ Passo 1: Verificar e Instalar o GCC

Abra o terminal (ou Prompt de Comando/PowerShell no Windows) e digite:

```bash
gcc --version
```

- **Apareceu uma versão?** 🎉 Você já tem tudo pronto — pule direto para [Compilar e Executar](#-compilar-e-executar-todos-os-sistemas).
- **Deu erro / "comando não encontrado"?** Escolha seu sistema operacional abaixo e siga a instalação.

---

<details>
<summary><strong>🐧 Linux (Ubuntu/Debian/Fedora)</strong> — clique para expandir</summary>

### Instalar GCC

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install gcc
```

**Fedora:**
```bash
sudo dnf install gcc
```

Depois de instalar, confirme com `gcc --version` e siga para [Compilar e Executar](#-compilar-e-executar-todos-os-sistemas).

</details>

---

<details>
<summary><strong>🍎 macOS</strong> — clique para expandir</summary>

### Opção A: Homebrew (recomendado)

Se já tem Homebrew instalado:
```bash
brew install gcc
```

Se não tiver Homebrew, instale primeiro:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### Opção B: Clang (já vem no macOS, não precisa instalar nada)

```bash
clang --version
```

Se aparecer uma versão, você pode usar `clang` no lugar de `gcc` em todos os comandos deste guia.

Depois, siga para [Compilar e Executar](#-compilar-e-executar-todos-os-sistemas).

</details>

---

<details>
<summary><strong>🪟 Windows</strong> — clique para expandir</summary>

### Opção A: MinGW-w64 (recomendado)

1. Acesse [mingw-w64.org](https://www.mingw-w64.org/)
2. Clique em **Downloads**
3. Escolha a versão **x86_64** (computadores modernos)
4. Baixe o instalador e siga as instruções
5. Adicione o MinGW ao PATH do Windows (geralmente é automático)
6. Confirme com `gcc --version` no Prompt de Comando ou PowerShell

### Opção B: WSL (Linux dentro do Windows)

```powershell
wsl --install
```

Depois de instalado, abra o WSL e siga as instruções da seção **Linux** acima — dentro do WSL tudo funciona igual a um Linux normal.

Depois de instalar, siga para [Compilar e Executar](#-compilar-e-executar-todos-os-sistemas).

</details>

---

## ⚙️ Compilar e Executar (todos os sistemas)

### 1️⃣ Navegar até a pasta do projeto

**Linux/macOS:**
```bash
cd /caminho/para/mp-ip-magicLibrary/magicLibrary
```

**Windows (cmd):**
```cmd
cd C:\caminho\para\mp-ip-magicLibrary\magicLibrary
```

### 2️⃣ Compilar

```bash
gcc -o biblioteca main.c biblioteca.c arquivo.c cripto.c -Wall -Wextra
```

> No macOS com Clang, troque `gcc` por `clang` no comando acima.

**O que cada parte faz:**
| Parte | Função |
|---|---|
| `gcc` | compilador C |
| `-o biblioteca` | nome do executável gerado |
| `main.c biblioteca.c arquivo.c cripto.c` | arquivos-fonte a compilar |
| `-Wall -Wextra` | ativa avisos de compilação |

### 3️⃣ Executar

**Linux/macOS:**
```bash
./biblioteca dados.txt
```

**Windows:**
```cmd
biblioteca.exe dados.txt
```
ou simplesmente:
```cmd
biblioteca dados.txt
```

✅ **Pronto!** O menu da Biblioteca Mágica deve aparecer.

---

## 🎮 Usando o Programa

```
╔══════════════════════════════════════╗
║      📚  BIBLIOTECA MÁGICA  📚       ║
╠══════════════════════════════════════╣
║  [1] Cadastrar livro                 ║
║  [2] Deletar livro                   ║
║  [3] Mostrar livro                   ║
║  [4] Editar livro                    ║
║  [5] Listar títulos                  ║
║  [6] Sair                            ║
╚══════════════════════════════════════╝
Escolha uma opção: _
```

Basta digitar o número da opção desejada e pressionar **Enter**.

💾 Os dados são salvos em `dados.txt` — não delete esse arquivo se quiser manter seu progresso.

---

## 🐛 Troubleshooting

| Erro | Causa provável | Solução |
|---|---|---|
| `gcc: comando não encontrado` | GCC não instalado ou não está no PATH | Linux: `sudo apt install gcc` · macOS: `brew install gcc` · Windows: reinstalar MinGW e conferir o PATH |
| `arquivo.c: No such file or directory` | Você não está na pasta certa | Confirme com `ls` (Linux/macOS) ou `dir` (Windows) se os arquivos `.c` estão ali |
| `undefined reference to...` | Faltou compilar algum arquivo `.c` | Use exatamente: `gcc -o biblioteca main.c biblioteca.c arquivo.c cripto.c -Wall -Wextra` |
| `Permission denied (./biblioteca)` | Falta permissão de execução | Rode `chmod +x biblioteca` (Linux/macOS) |

---

## ✨ Dicas Extras

- 🔄 Depois de mudar o código, é só rodar o comando `gcc` de novo para recompilar.
- 🧹 Para limpar o executável: `rm biblioteca` (Linux/macOS) ou `del biblioteca.exe` (Windows).
- 📁 Sempre confirme que está dentro da pasta `magicLibrary` antes de compilar.

---

**Pronto para a aventura na Biblioteca Mágica? 🧙‍♂️📖**