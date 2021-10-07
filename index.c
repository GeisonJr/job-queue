/****************************************************************************
*
* 201910452 - Felipe Santos Chaparim
* 201910467 - Geison Rodrigo Oriani Junior
* 201910206 - Maicon Vitor Riberio de Oliveira
*
* Job Queue
*
****************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define first 100;

int nextPosition = 0, nextPID = 0;

typedef struct
{
	int pid, cpu, io, status;
	char name[5], type[2];
} Process;

Process processes[10];

void insertProc();
void ListOne();
void changeProc();
void removeOne();
void listAll();
void removeAll();
void bubbleSort();

int main()
{
	int option;
	do
	{
		system("clear");
		printf("\n Gerenciador de Processos");
		printf("\n ----------------------------------");
		// printf("\n  0 - Gerador de Processos. (caso queira gerar automaticamente 10 processos)");
		printf("\n  1 - Inserir Novo Processo.");
		printf("\n  2 - Exibir Dados de um Processo.");
		printf("\n  3 - Alterar Dados de um Processo.");
		printf("\n  4 - Remover um Processo.");
		printf("\n  5 - Exibir Todos os Processos.");
		printf("\n  6 - Remover Todos os Processos.");
		printf("\n  7 - Executar o Gerenciador de Processos.");
		printf("\n  8 - Exibir os Participantes da Equipe.");
		printf("\n  9 - Sair do Programa.");
		printf("\n ----------------------------------");
		printf("\n Opcao(0-9): ");
		scanf("%i", &option);
		fflush(stdin);
	} while (option < 1 || option > 9);
	// } while (option < 0 || option > 9);

	switch (option)
	{
	// case 0:
	// 	/* Gerador de Processos */ // OK
	// 	system("clear");
	// 	if (!(nextPosition < 10))
	// 	{
	// 		printf("\n A Lista esta Cheia, Remova ao Menos um Processo para Inserir um Processo");
	// 	}
	// 	else
	// 	{
	// 		for (int i = 0; i < 10 - nextPosition; i++)
	// 		{
	// 			int ref1 = i + 1, ref2 = ref1 % 3;
	// 			char buffer[4];

	// 			if (ref2 == 0)
	// 			{
	// 				strcpy(processes[nextPosition].type, "SO");
	// 			}
	// 			else if (ref2 == 1)
	// 			{
	// 				strcpy(processes[nextPosition].type, "IN");
	// 			}
	// 			else
	// 			{
	// 				strcpy(processes[nextPosition].type, "NI");
	// 			}
	// 			strcpy(processes[nextPosition].name, itoa(ref1, buffer, 10));
	// 			processes[nextPosition].status = 0;
	// 			processes[nextPosition].pid = nextPID + first;
	// 			processes[nextPosition].cpu = rand() % 10;
	// 			processes[nextPosition].io = rand() % 10;
	// 			nextPosition++;
	// 			nextPID++;
	// 		}
	// 		printf("\n Processo inserido com sucesso!");
	// 	}
	// 	printf("\n\n Precione Qualquer Tecla Para Continuar...");
	// 	break;
	case 1:
		/* Inserir Novo Processo */ // OK
		system("clear");
		if (!(nextPosition < 10))
		{
			printf("\n A Lista esta Cheia, Remova ao Menos um Processo para Inserir um Processo");
		}
		else
		{
			insertProc();
			system("clear");
			printf("\n\n Processo Inserido com Sucesso!");
		}
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 2:
		/* Exibir Dados de um Processo */ // OK
		system("clear");
		if (nextPosition == 0)
		{
			printf("\n A Lista esta Vazia, Insira ao Menos um Processo para Exibir um Processo");
		}
		else
		{
			ListOne();
			printf("\n ----------------------------------");
			printf("\n\n Processo Listado com Sucesso!");
		}
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 3:
		/* Alterar Dados de um Processo */ // OK
		system("clear");
		if (nextPosition == 0)
		{
			printf("\n A Lista esta Vazia, Insira ao Menos um Processo para Alterar Um Processo");
		}
		else
		{
			changeProc();
			printf("\n ----------------------------------");
			printf("\n\n Processo Alterado com Sucesso!");
		}
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 4:
		/* Remover um Processo */ // OK
		system("clear");
		if (nextPosition == 0)
		{
			printf("\n A Lista esta Vazia, Insira ao Menos um Processo para Remover Um Processo");
		}
		else
		{
			removeOne();
			printf("\n Processo Removido com Sucesso!");
		}
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 5:
		/* Exibir Todos os Processos */ // OK
		system("clear");
		if (nextPosition == 0)
		{
			printf("\n A Lista esta Vazia, Insira ao Menos um Processo para Listar Todos os Processos");
		}
		else
		{
			printf("\n PID\tNOME\tTIPO\tCPU\tI/O");
			printf("\n ----------------------------------");
			listAll();
			printf("\n ----------------------------------");
			printf("\n\n Processos Listados com Sucesso!");
		}
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 6:
		/* Remover Todos os Processos */ // OK
		system("clear");
		if (nextPosition == 0)
		{
			printf("\n A Lista esta Vazia, Insira ao Menos um Processo para Remover Todos os Processos");
		}
		else
		{
			removeAll();
			printf("\n Processos Removidos com Sucesso!");
		}
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 7:
		/* Executar o Gerenciador de Processos */ // OK
		system("clear");
		if (nextPosition == 0)
		{
			printf("\n A Lista esta Vazia, Insira ao Menos um Processo para Executalo");
		}
		else
		{
			printf("\n PID\tNOME\tTIPO\tCPU\tI/O\tENCERRADO");
			printf("\n ------------------------------------------------");
			bubbleSort();
			printf("\n ------------------------------------------------");
			printf("\n Processos Executados com Sucesso!");
		}
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 8:
		/* Exibir os Participantes da Equipe */ // OK
		system("clear");
		printf("\n RA\t\tNOME");
		printf("\n ------------------------------------------------");
		printf("\n  201910452\tFelipe Santos Chaparim");
		printf("\n  201910467\tGeison Rodrigo Oriani Junior");
		printf("\n  201910206\tMaicon Vitor Riberio de Oliveira");
		printf("\n ------------------------------------------------");
		printf("\n\n Precione Qualquer Tecla Para Continuar...");
		break;
	case 9:
		/* Sair do Programa */ // OK
		system("clear");
		printf("\n Encerrando...");
		exit(0);
	default:
		/* Escolha Invalida */ // OK
		system("clear");
		printf("\n Escolha Invalida");
		printf("\n\n Precione Qualquer Tecla Para Tentar Novamente...");
		break;
	}
	system("pause>null");
	main();
	return 0;
}

void insertProc()
{
	char name[5], type[2];
	int pid = nextPID + first;
	int cpu = 0, io = 0;

	printf("\n PID: %d\n", pid);
	processes[nextPosition].pid = pid;
name:
	printf(" NOME: ");
	scanf("%s", &name);
	for (int i = 0; i < nextPosition; i++)
	{
		if (strcmp(processes[i].name, name) == 0)
		{
			printf("\r Esse Nome ja Existe, Tente Novamente\n");
			goto name;
		}
	}
	strcpy(processes[nextPosition].name, name);
	fflush(stdin);
tipo:
	printf(" TIPO: ");
	scanf("%s", &type);
	if (strcmp(type, "SO") != 0 && strcmp(type, "IN") != 0 && strcmp(type, "NI") != 0)
	{
		printf("\r Esse Tipo nao Existe, Tente Novamente\n");
		goto tipo;
	}
	strcpy(processes[nextPosition].type, type);
	fflush(stdin);
cpu:
	printf(" CPU: ");
	scanf("%d", &cpu);
	if (cpu < 0)
	{
		printf("\r Esse Valor e invalido, Tente Novamente\n");
		goto cpu;
	}
	processes[nextPosition].cpu = cpu;
	fflush(stdin);
io:
	printf(" I/O: ");
	scanf("%d", &io);
	if (io < 0)
	{
		printf("\r Esse Valor e invalido, Tente Novamente\n");
		goto io;
	}
	processes[nextPosition].io = io;
	fflush(stdin);

	processes[nextPosition].status = 0;
	nextPosition++;
	nextPID++;
}

void ListOne()
{
	int pid = 0;
	printf("\n\n Digite o PID: ");
	scanf("%d", &pid);
	fflush(stdin);

	printf("\n PID\tNOME\tTIPO\tCPU\tI/O");
	printf("\n ----------------------------------");
	for (int i = 0; i < nextPosition; i++)
	{
		if (processes[i].pid == pid)
		{
			printf("\n %d\t%s\t%s\t%d\t%d", processes[i].pid, processes[i].name, processes[i].type, processes[i].cpu, processes[i].io);
		}
	}
}

void changeProc()
{
	int pid = 0;
	printf("\n\n Digite o PID: ");
	scanf("%d", &pid);
	fflush(stdin);

	for (int i = 0; i < nextPosition; i++)
	{
		if (processes[i].pid == pid)
		{
			char name[5], type[2];
			int cpu = 0, io = 0;

			printf("\n PID: %d", pid);
		name:
			printf(" NOME: ");
			scanf("%s", &name);
			for (int i = 0; i < nextPosition; i++)
			{
				if (strcmp(processes[i].name, name) == 0)
				{
					printf("\r Esse Nome ja Existe, Tente Novamente\n");
					goto name;
				}
			}
			strcpy(processes[nextPosition].name, name);
			fflush(stdin);
		tipo:
			printf(" TIPO: ");
			scanf("%s", &type);
			if (strcmp(type, "SO") != 0 && strcmp(type, "IN") != 0 && strcmp(type, "NI") != 0)
			{
				printf("\r Esse Tipo nao Existe, Tente Novamente\n");
				goto tipo;
			}
			strcpy(processes[nextPosition].type, type);
			fflush(stdin);
		cpu:
			printf(" CPU: ");
			scanf("%d", &cpu);
			if (cpu < 0)
			{
				printf("\r Esse Valor e invalido, Tente Novamente\n");
				goto cpu;
			}
			processes[nextPosition].cpu = cpu;
			fflush(stdin);
		io:
			printf(" I/O: ");
			scanf("%d", &io);
			if (io < 0)
			{
				printf("\r Esse Valor e invalido, Tente Novamente\n");
				goto io;
			}
			processes[nextPosition].io = io;
			fflush(stdin);
		}
	}
}

void removeOne()
{
	int pid;
	printf("\n Digite o PID: ");
	scanf("%d", &pid);
	fflush(stdin);

	Process keepList[10];

	int id = 0;

	for (int i = 0; i < nextPosition; i++)
	{
		if (processes[i].pid != pid)
		{
			keepList[id] = processes[i];
			id++;
		}
	}

	memcpy(processes, keepList, sizeof(keepList));
	nextPosition--;
}

void listAll()
{
	for (int i = 0; i < nextPosition; i++)
	{
		printf("\n %d\t%s\t%s\t%d\t%d", processes[i].pid, processes[i].name, processes[i].type, processes[i].cpu, processes[i].io);
	}
}

void removeAll()
{
	Process emptyList[10];

	memcpy(processes, emptyList, sizeof(emptyList));
	nextPosition = 0;
}

void bubbleSort()
{
	Process endedProcess[10], orderlyProcess[10];
	int bloqueado = 0;

	int ordaindedID = 0;
	int maxSO = 0, maxIN = 0, maxNI = 0;

	int endedID = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int x = 0; x < nextPosition; x++)
		{

			if (strcmp(processes[x].type, "SO") == 0 && i == 0)
			{
				orderlyProcess[ordaindedID].io = processes[x].io;
				orderlyProcess[ordaindedID].cpu = processes[x].cpu;
				orderlyProcess[ordaindedID].pid = processes[x].pid;
				orderlyProcess[ordaindedID].status = processes[x].status;
				strcpy(orderlyProcess[ordaindedID].type, processes[x].type);
				strcpy(orderlyProcess[ordaindedID].name, processes[x].name);
				ordaindedID++;
				maxSO++;
			}
			else if (strcmp(processes[x].type, "IN") == 0 && i == 1)
			{
				orderlyProcess[ordaindedID].io = processes[x].io;
				orderlyProcess[ordaindedID].cpu = processes[x].cpu;
				orderlyProcess[ordaindedID].pid = processes[x].pid;
				orderlyProcess[ordaindedID].status = processes[x].status;
				strcpy(orderlyProcess[ordaindedID].type, processes[x].type);
				strcpy(orderlyProcess[ordaindedID].name, processes[x].name);
				ordaindedID++;
				maxIN++;
			}
			else if (strcmp(processes[x].type, "NI") == 0 && i == 2)
			{
				orderlyProcess[ordaindedID].io = processes[x].io;
				orderlyProcess[ordaindedID].cpu = processes[x].cpu;
				orderlyProcess[ordaindedID].pid = processes[x].pid;
				orderlyProcess[ordaindedID].status = processes[x].status;
				strcpy(orderlyProcess[ordaindedID].type, processes[x].type);
				strcpy(orderlyProcess[ordaindedID].name, processes[x].name);
				ordaindedID++;
				maxNI++;
			}
		}
	}

	for (int z = 0; z < 100; z++)
	{
		for (int i = 0; i < maxSO; i++)
		{
			if (strcmp(orderlyProcess[i].type, "SO") == 0)
			{
				if (orderlyProcess[i].cpu > 0)
				{
					orderlyProcess[i].cpu--;
				}
				if (orderlyProcess[i].io > 0)
				{
					if (bloqueado == 0)
					{
						bloqueado = orderlyProcess[i].pid;
						orderlyProcess[i].io--;
					}
				}
				if (orderlyProcess[((i + 1) > maxSO - 1) ? 0 : (i + 1)].io > 0)
				{
					bloqueado = 0;
				}
				if (orderlyProcess[i].cpu == 0 && orderlyProcess[i].io == 0 && orderlyProcess[i].status == 0)
				{
					orderlyProcess[i].status = 1;
					endedProcess[endedID].io = orderlyProcess[i].io;
					endedProcess[endedID].cpu = orderlyProcess[i].cpu;
					endedProcess[endedID].pid = orderlyProcess[i].pid;
					endedProcess[endedID].status = orderlyProcess[i].status;
					strcpy(endedProcess[endedID].name, orderlyProcess[i].name);
					strcpy(endedProcess[endedID].type, orderlyProcess[i].type);
					endedID++;
				}
			}
		}
	}

	for (int z = 0; z < 100; z++)
	{
		for (int i = maxSO; i < maxSO + maxIN; i++)
		{
			if (strcmp(orderlyProcess[i].type, "IN") == 0)
			{
				if (orderlyProcess[i].cpu > 0)
				{
					orderlyProcess[i].cpu--;
				}
				if (orderlyProcess[i].io > 0)
				{
					if (bloqueado == 0)
					{
						bloqueado = orderlyProcess[i].pid;
						orderlyProcess[i].io--;
					}
				}
				if (orderlyProcess[((i + 1) > maxSO + maxIN - 1) ? maxSO : (i + 1)].io > 0)
				{
					bloqueado = 0;
				}
				if (orderlyProcess[i].cpu == 0 && orderlyProcess[i].io == 0 && orderlyProcess[i].status == 0)
				{
					orderlyProcess[i].status = 1;
					endedProcess[endedID].io = orderlyProcess[i].io;
					endedProcess[endedID].cpu = orderlyProcess[i].cpu;
					endedProcess[endedID].pid = orderlyProcess[i].pid;
					endedProcess[endedID].status = orderlyProcess[i].status;
					strcpy(endedProcess[endedID].name, orderlyProcess[i].name);
					strcpy(endedProcess[endedID].type, orderlyProcess[i].type);
					endedID++;
				}
			}
		}
	}

	for (int z = 0; z < 100; z++)
	{
		for (int i = maxIN; i < maxSO + maxIN + maxNI; i++)
		{
			if (strcmp(orderlyProcess[i].type, "NI") == 0)
			{
				if (orderlyProcess[i].cpu > 0)
				{
					orderlyProcess[i].cpu--;
				}
				if (orderlyProcess[i].io > 0)
				{
					if (bloqueado == 0)
					{
						bloqueado = orderlyProcess[i].pid;
						orderlyProcess[i].io--;
					}
				}
				if (orderlyProcess[((i + 1) > maxSO + maxIN + maxNI - 1) ? maxSO + maxIN : (i + 1)].io > 0)
				{
					bloqueado = 0;
				}
				if (orderlyProcess[i].cpu == 0 && orderlyProcess[i].io == 0 && orderlyProcess[i].status == 0)
				{
					orderlyProcess[i].status = 1;
					endedProcess[endedID].io = orderlyProcess[i].io;
					endedProcess[endedID].cpu = orderlyProcess[i].cpu;
					endedProcess[endedID].pid = orderlyProcess[i].pid;
					endedProcess[endedID].status = orderlyProcess[i].status;
					strcpy(endedProcess[endedID].name, orderlyProcess[i].name);
					strcpy(endedProcess[endedID].type, orderlyProcess[i].type);
					endedID++;
				}
			}
		}
	}

	for (int i = 0; i < nextPosition; i++)
	{
		printf("\n %d\t%s\t%s\t%d\t%d\t%dth", endedProcess[i].pid, endedProcess[i].name, endedProcess[i].type, endedProcess[i].cpu, endedProcess[i].io, i + 1);
	}
}