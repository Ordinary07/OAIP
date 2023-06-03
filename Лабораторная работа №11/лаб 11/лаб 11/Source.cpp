#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale>




int main()
{
	FILE* fin;
	FILE* fout;
	char str[255];
	fopen_s(&fin, "C:\\TEMP\\int11_b.txt", "rt");
	fopen_s(&fout, "C:\\TEMP\\out11_b.txt", "wt");
	while (!feof(fin))
	{
		fgets(str, 255, fin);
		fprintf(fout, "<HTML>\n<HEAD>\n<TITLE>lab11</TITLE>\n</HEAD>\n<BODY>", str); //\n<H1>%s<BR></H1>
		int colvo = 0;
		int i = 0;
		fprintf(fout, "<H1></H1>");
		while (str[i] != 0)
		{
			if (str[i] == 'A')

				colvo++;

			i++;


		}

		if (colvo > 0)
		{
			fprintf(fout, "<i> <b> %s</b></i><br>", str);
			//fprintf(fout, "</i> </b><br>"); //</H1><BR>
		}
		if (colvo == 0)
		{
			fprintf(fout, "%s<br>", str);
		}






	}


	fprintf(fout, "</BODY>\n</HTML>");
	fclose(fin);
	fclose(fout);




}
