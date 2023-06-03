#include <stdio.h>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");

	FILE* fin;
	FILE* fout;
	fopen_s(&fin, "C:\\TEMP\\int11_b.txt", "rt");
	fopen_s(&fout, "C:\\TEMP\\out11_b.txt", "wt");
	fprintf(fout, "<HTML><HEAD><TITLE>");
	char str[256];
	fgets(str, 256, fin);
	fprintf(fout, "%s</TITLE></HEAD>\n<BODY>\n<H1>%s<BR></H1>\n", str, str);
	while (!feof(fin))
	{
		fgets(str, 256, fin);
		bool Acnt = false;
		int i = 0;
		while (str[i] != 0)
		{
			if (str[i] == 'r' && str[i + 1] == 'r')
			{
				Acnt = true;
				break;
			}
			i++;
		}
		if (Acnt)
		{
			fprintf(fout, "<i><b>%s<BR></b></i>", str);
		}
		else
		{
			fprintf(fout, "%s<BR>", str);
		}
		str[0] = 0;
	}
	fprintf(fout, "</BODY></HTML>");

	fclose(fin);
	fclose(fout);

	return 0;
}