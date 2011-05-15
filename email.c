#include<stdio.h>
#include<string.h>

char str[1024] = { 0 };

void get_email(const char *str)
{
	int i;
	int m, n, t;
	for (i = 0; str[i] != '\n'; i++) {
		if(str[i] == '@') {
			m = i;
			n = i;
        if(i == 0)
          continue;
			while (m > 0) {
				if (str[m - 1] <= 'z' && str[m - 1] >= 'a'
				    || str[m - 1] <= 'Z'
				    && str[m - 1] >= 'A'
				    || str[m - 1] <= '9'
				    && str[m - 1] >= '0'
				    || str[m - 1] == '.'
				    || str[m - 1] == '_')
					m--;
				else
					break;
            }    if(i - m >32)
                break;
			while (n < 1024){
				if (str[n + 1] <= 'z' && str[n + 1] >= 'a'
				    || str[n + 1] <= 'Z'
				    && str[n + 1] >= 'A'
				    || str[n + 1] <= '9'
				    && str[n + 1] >= '0'
				    || str[n + 1] == '.'
				    || str[n + 1] == '-')
					n++;
				else
					break; 
            }
                    if(n -i > 64)
                    break;        
			if (m == i || n == i)
				break;
			for (t = m; t <= n; t++)
				printf("%c", str[t]);
			printf("\n");
            i = n + 1;
		}
}
}


int main(int argc, const char *argv[])
{

	FILE *file = fopen("1.html", "r");
	if (!file) {
		fclose(file);
		printf("fail to open!\n");
	} else
		//       while(!feof(file)){
		//         fgets(str,sizeof(str),file);
		while (fgets(str, sizeof(str), file) != NULL) {


			get_email(str);
		}

}
