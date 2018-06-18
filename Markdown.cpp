#include <cstdio>
#include <cstring>
const int N = 100 + 5;
char buf[N][N] = { 0 };

inline int is_head(char *buf) {
	if (buf[0] == '#') return 1;
	return 0;
}

inline int is_list(char *buf) {
	if (buf[0] == '*') return 1;
	return 0;
}

inline int is_space(char *buf) {
	if (strcmp("\n", buf) == 0) return 1;
	return 0;
}

void routine(int i, int len, int con) {
	buf[i][strlen(buf[i]) - 1] = 0;
	if (con && i + 1 < len && !is_space(buf[i + 1]) && !is_list(buf[i + 1]) && !is_head(buf[i + 1]))
		buf[i][strlen(buf[i])] = '\n';
	int flag = 0, count = 0;
	char text[N] = { 0 }, link[N] = { 0 };
	for (int j = 0; j < strlen(buf[i]); j++) {
		if (buf[i][j] == '_' && !flag) {
			printf("<em>");
			flag = !flag;
			continue;
		}
		if (buf[i][j] == '_' && flag) {
			printf("</em>");
			flag = !flag;
			continue;
		}
		if (buf[i][j] == '[') {
			count = 0;
			j++;
			for (; buf[i][j] != ']'; j++) text[count++] = buf[i][j];
			j++;
		}
		if (buf[i][j] == '(') {
			int sign = 0;
			count = 0;
			j++;
			for (; buf[i][j] != ')'; j++) link[count++] = buf[i][j];
			printf("<a href=\"");
			for (int w = 0; w <= strlen(link); w++) {
				if (link[w] == '_' && !sign) {
					printf("<em>");
					sign = !sign;
					continue;
				}
				if (link[w] == '_' && sign) {
					printf("</em>");
					sign = !sign;
					continue;
				}
				if (link[w] != '\0') printf("%c", link[w]);
			}
			printf("\">");
			for (int w = 0; w <= strlen(text); w++) {
				if (text[w] == '_' && !sign) {
					printf("<em>");
					sign = !sign;
					continue;
				}
				if (text[w] == '_' && sign) {
					printf("</em>");
					sign = !sign;
					continue;
				}
				if (text[w] != '\0') printf("%c", text[w]);
			}
			printf("</a>");
			memset(link, 0, sizeof(link));
			memset(text, 0, sizeof(text));
			continue;
		}
		if (buf[i][j] != '\0') printf("%c", buf[i][j]);
	}
}

int main() {
	int len = 0;
	for (; fgets(buf[len], N, stdin); len++);

	for (int i = 0; i < len; i++) {
		if (is_space(buf[i])) continue;
		else if (is_head(buf[i])) {
			int level = 0;
			for (; ; level++) if (buf[i][level] != '#') break;
			while (buf[i][0] == ' ' || buf[i][0] == '#') {
				for (int j = 0; j < strlen(buf[i]); j++) {
					char t = buf[i][j];
					buf[i][j] = buf[i][j + 1];
					buf[i][j + 1] = t;
				}
				//buf[i][strlen(buf[i]) - 1] = 0;
			}
			printf("<h%d>", level);
			routine(i, len, 0);
			printf("</h%d>\n", level);
			continue;
		}
		else if (is_list(buf[i])) {
			printf("<ul>\n");
			for (; is_list(buf[i]); i++) {
				while (buf[i][0] == '*' || buf[i][0] == ' ') {
					for (int j = 0; j < strlen(buf[i]); j++) {
						char t = buf[i][j];
						buf[i][j] = buf[i][j + 1];
						buf[i][j + 1] = t;
					}
					//buf[i][strlen(buf[i]) - 1] = 0;
				}
				printf("<li>");
				routine(i, len, 0);
				printf("</li>\n");
			}
			i--;
			printf("</ul>\n");
			continue;
		}
		else {
			printf("<p>");
			for (; !is_space(buf[i]) && !is_head(buf[i]) && !is_list(buf[i]) && i <= len; i++)
				routine(i, len, 1);
			printf("</p>\n");
			i--;
			continue;
		}
	}

	return 0;
}
