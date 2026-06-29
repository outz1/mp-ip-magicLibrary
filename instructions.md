# Mini Projeto 03 - Backend de Jogo: Biblioteca Mágica

## Conteúdo: Structs, Ponteiros, Alocação Dinâmica e Manipulação de Arquivos

### Instruções Gerais:

- O projeto deverá ser realizado em grupos de 4 pessoas.
- Os arquivos que deverão ser entregues são: 
   1. O(s) código(s) `.c`; 
   2. O vídeo de apresentação; 
   3. O arquivo `README.md` com link para o **GitHub**; 
- **GitHub obrigatório:** todo o desenvolvimento deve estar em um repositório público no **GitHub**, e o link deve estar no `README.md`. O uso de ferramentas de IA para **aprender a usar o GitHub** (commits, repositórios, etc.) é permitido.
- É obrigatória a organização e padronização do código. Nomes de variáveis e funções devem ser coerentes com seus propósitos (ex: `cadastrarLivro`, `id`, `livroMagico`). São permitidas exceções para variáveis de uso comum em programação, como `i`, `j`, `temp`, `ans`, entre outras.
- Os monitores estão disponíveis apenas para sanar dúvidas, dar ideias e auxiliar na parte teórica, mas **não irão ajudar na codificação**.
- É permitido o uso de ferramentas de IA para auxiliar no **aprendizado** de conceitos não abordados em aula e de novas bibliotecas em C para tornar o código mais interessante. No entanto, o plágio (código 100% gerado por IA sem compreensão do aluno) resultará em **nota zero** para o grupo. A estrutura mínima solicitada aqui deve ser construída pelos alunos.

---

### Instruções para o README.md:

- O readme serve para dar uma breve introdução de como utilizar o sistema desenvolvido.
- É permitido usar IA para a construção do README.
- Os integrantes do grupo deverão estar todos listados.
- O link do projeto no GitHub deve estar obrigatoriamente no README.

---

### Instruções para o Vídeo de Apresentação:

- **Duração:** De 15 a 20 minutos.
- Todos os membros devem aparecer no vídeo (utilizando webcams), porém o tempo de apresentação de cada um pode variar de acordo com a divisão feita pelo grupo.
- O vídeo poderá ser editado da forma como o grupo preferir, objetivando maior fluidez e didática.
- **Sugestão de roteiro:**
    1. Apresentação do `README.md` (mostrando como utilizar o código);
    2. Apresentação do código por completo e explicação de seu funcionamento;
    3. Demonstração prática do uso do sistema, incluindo o salvamento e carregamento de arquivos, e uso de alguns casos de teste.

---

### Ideia Geral do Projeto:

Neste projeto, vocês atuarão como desenvolvedores criando o **backend de um Jogo de RPG**. O desafio é programar o sistema responsável pelo **Inventário da Biblioteca Mágica** do jogo, utilizando Structs, Vetores de Ponteiros, Alocação Dinâmica e Arquivos. O sistema deve gerenciar e armazenar os atributos de diferentes livros colecionados pelo jogador durante a campanha, mantendo o "save game" desse inventário persistente (para que os itens não se percam quando o jogo for fechado, gravando-os e lendo-os do disco).

Ir além do mínimo (criatividade) é **muito incentivado e recomendado**. O grupo pode adicionar novas funcionalidades,utilizar novas bibliotecas e fazer melhorias. Entretanto, a **estrutura mínima** detalhada aqui é **obrigatória** — não será aceito nenhum projeto que implemente menos do que as funções listadas e os requisitos de organização.

- **Gerenciamento na Memória:** O programa deve manter um **vetor de ponteiros** para a struct `LivroMagico`, com **100 posições**. Cada posição deste vetor pode conter:
  - Um ponteiro válido para um livro alocado dinamicamente.
  - `NULL` indicando que a posição (slot no inventário / prateleira) está vazia.
- As operações devem rodar em loop através de um menu principal, garantindo que o usuário possa interagir continuamente com o catálogo até escolher a opção de sair.
- **Identificação:** A identificação de cada livro para edições e exclusões deve ser feita pelo seu `id` (ou seja, você precisará iterar o vetor até encontrar o livro com o `id` procurado), e não pela sua posição do vetor (índice).
- **Parâmetro da Main:** O nome do arquivo que será utilizado para leitura/escrita de dados deverá ser passado como parâmetro de linha de comando para a função `main` (ex: `./programa biblioteca.txt`).
- **Criptografia:** A informação de texto referente ao **`titulo`** do livro deve ser obrigatoriamente **criptografada** por uma função própria antes de ser salva no arquivo, e **descriptografada** ao ser carregada para a memória (o restante das informações não precisam ser criptografadas, apenas se o grupo quiser).
- **Opções do Menu:** O menu principal deve interagir com o usuário fornecendo, no mínimo, as seguintes opções:
  1. Cadastro de livro
  2. Deleção de livro
  3. Mostrar livro
  4. Editar livro
  5. Listar títulos dos livros
  6. Sair


---

### Estruturas (Structs) a serem implementadas:

Os tipos e nomenclaturas exatas podem ser adaptados pelo grupo, mas **devem obrigatoriamente sustentar a seguinte lógica de dados**:

1. **Struct Data**
   - `int` dia
   - `int` mes
   - `int` ano

2. **Struct Autor**
   - `char` nome[100]
   - `struct Data` data_nascimento

3. **Struct LivroMagico**
   - `int` id (Identificador único do livro)
   - `char` titulo[100]
   - `struct Autor` autor
   - `struct Data` data_escrita

---

### Funções a serem implementadas:

Os tipos de retorno e os nomes exatos das funções podem ser de livre escolha, mas **devem implementar as seguintes operações e utilizar passagem por referência do vetor de ponteiros**:

1. **`void inicializarVetor(struct LivroMagico **biblioteca);`**
   - Percorre o vetor de ponteiros e inicializa todas as posições com `NULL`.

2. **`void cadastrarLivro(struct LivroMagico **biblioteca);`**
   - Encontra uma posição livre (`NULL`), aloca memória dinâmica para um novo `LivroMagico`, preenche com os dados informados pelo usuário e salva o ponteiro no vetor.

3. **`void deletarLivro(struct LivroMagico **biblioteca, int id);`**
   - Busca o livro pelo `id`. Se encontrar, libera a memória (`free`) e devolve `NULL` para a posição do vetor.

4. **`void mostrarLivro(struct LivroMagico **biblioteca, int id);`**
   - Busca o livro pelo `id` e exibe todas as suas informações formatadas na tela.

5. **`void editarLivro(struct LivroMagico **biblioteca, int id);`**
   - Busca o livro pelo `id` e permite ao usuário reescrever os seus atributos.

6. **`void listarTitulos(struct LivroMagico **biblioteca);`**
   - Itera pelo vetor e, para cada posição ocupada, imprime na tela o `id` e o `titulo` do livro correspondente.

7. **`void salvarBiblioteca(struct LivroMagico **biblioteca, const char *nomeArquivo);`**
   - Abre o arquivo informado e salva todos os dados dos livros cadastrados. **Importante:** A string do `titulo` deve ser criptografada antes do salvamento.

8. **`void carregarBiblioteca(struct LivroMagico **biblioteca, const char *nomeArquivo);`**
    - Abre o arquivo, lê os registros, aloca dinamicamente cada `LivroMagico` e os adiciona ao vetor em posições livres. A string do `titulo` deve ser descriptografada logo após a leitura. Deve ser chamada no início do programa.

9. **`void criptografar(char* str);`**
    - Criptografa a string utilizando **complemento de 255**: para cada caractere `c` da string, substitui-o por `(char)(255 - (unsigned char)c)`. A operação é sua própria inversa, portanto a mesma lógica serve para criptografar e descriptografar.

10. **`void descriptografar(char* str);`**
    - Reverte a string criptografada aplicando novamente o complemento de 255 (mesma operação de `criptografar`).

---

### Critérios de Avaliação:

| Critério | Peso |
|---|---|
| Organização do código | 10% |
| Criatividade | 15% |
| Cadastro de livro (opção do menu) | 15% |
| Deleção de livro (opção do menu) | 15% |
| Mostrar livro (opção do menu) | 15% |
| Editar livro (opção do menu) | 15% |
| Listar títulos dos livros (opção do menu) | 15% |
| **Total** | **100%** |

**Atenção:** A falta de qualquer um dos arquivos obrigatórios (vídeo, código(s) ou readme) resultará na **não correção** do projeto (nota zero). Além disso, o não cumprimento de outros detalhes e regras especificados neste documento também poderá acarretar em penalizações na nota final.