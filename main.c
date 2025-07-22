#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>

#define USER_FILE "usuario.txt"
#define MAX_USERNAME 50
#define MAX_PASSWORD 50
#define SALT_LENGTH 16

// Função para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função simulada de hash (para fins didáticos)
void hash_fake(const char *str, char output[65]) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    snprintf(output, 65, "%lx", hash);
}

// Gera um salt aleatório
void generate_salt(char *salt) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < SALT_LENGTH; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        salt[i] = charset[key];
    }
    salt[SALT_LENGTH] = '\0';
}

// Concatena salt e senha e retorna um hash
void hash_password(const char *password, const char *salt, char *output_hash) {
    char combined[MAX_PASSWORD + SALT_LENGTH + 1];
    snprintf(combined, sizeof(combined), "%s%s", salt, password);
    hash_fake(combined, output_hash);
}

// Cadastra um novo usuário
void register_user() {
    FILE *file = fopen(USER_FILE, "a+");
    if (!file) {
        printf("Erro ao abrir o arquivo de usuários.\n");
        return;
    }

    char username[MAX_USERNAME], password[MAX_PASSWORD];
    char salt[SALT_LENGTH + 1], hash[65];
    char line[MAX_USERNAME + SALT_LENGTH + 65 + 3];

    printf("Digite o nome de usuário: ", MAX_USERNAME - 1);
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    // Verifica se usuário já existe
    rewind(file);
    while (fgets(line, sizeof(line), file) != NULL) {
        char saved_username[MAX_USERNAME];
        if (sscanf(line, "%49[^\t]", saved_username) == 1) {
            if (strcmp(saved_username, username) == 0) {
                printf("O Usuário já existe.\n");
                fclose(file);
                return;
            }
        }
    }

    printf("Digite a senha: ", MAX_PASSWORD - 1);
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    generate_salt(salt);
    hash_password(password, salt, hash);

    fprintf(file, "%s\t%s\t%s\n", username, salt, hash);
    fclose(file);
    printf("Usuário '%s' cadastrado com sucesso.\n", username);
}

// Função de login
void login_user() {
    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        printf("Nenhum usuário cadastrado ainda.\n");
        return;
    }

    char username[MAX_USERNAME], password[MAX_PASSWORD];
    
    printf("Digite o nome de usuário: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Digite a senha: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    char line[MAX_USERNAME + SALT_LENGTH + 65 + 3];
    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char saved_username[MAX_USERNAME], saved_salt[SALT_LENGTH + 1], saved_hash[65];
        if (sscanf(line, "%49[^\t]\t%16[^\t]\t%64s", saved_username, saved_salt, saved_hash) == 3) {
            if (strcmp(saved_username, username) == 0) {
                found = 1;
                char computed_hash[65];
                hash_password(password, saved_salt, computed_hash);
                if (strcmp(computed_hash, saved_hash) == 0) {
                    printf("Login bem-sucedido! Bem-vindo(a), %s!\n", username);
                } else {
                    printf("Senha incorreta.\n");
                }
                break;
            }
        }
    }

    if (!found) {
        printf("Usuário não encontrado.\n");
    }

    fclose(file);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand((unsigned int)time(NULL));
    char input[10];
    int opcao;

    while (1) {
        printf("\n====== MENU ======\n");
        printf("1. Cadastro\n");
        printf("2. Login\n");
        printf("3. Sair\n");
        printf("Selecione uma opção: ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Erro ao ler entrada.\n");
            limpar_buffer();
            continue;
        }
        
        input[strcspn(input, "\n")] = '\0';
        
        if (strlen(input) == 0) {
            continue;
        }
        
        if (strlen(input) != 1 || !isdigit(input[0])) {
            printf("Opção inválida. Digite apenas 1, 2 ou 3.\n");
            continue;
        }
        
        opcao = input[0] - '0';

        switch (opcao) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                printf("encerrando...\n");
                return 0;
            default:
                printf("Opção inválida. Digite 1, 2 ou 3.\n");
        }
    }

    return 0;
}