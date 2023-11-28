#include <stdio.h>
#include <stdlib.h>
#include "Appliance.h"
#include "HomeAutomation.h"
#include <time.h>
#include <string.h>
#include "a"

#pragma warning(disable : 4996)

static void myFlush(void) {
	while (getchar() != '\n') {
		;
	}
}

Func_control controlAircon(APP_t* app) {
	
	int n;
	int n2;

	while (1) {
		displayAircon(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n", electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n3 : Select %smode\n4 : Set temperature\n", electromachine[app->Info.type]);
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n�� ��� ���� : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 2) {
			app->Info.powerflag = 0;
			app->Info.state1 = -1; // ������ ������
			if (app->Info.start_H) {
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
			}
			app->Info.start_H = 0; // OFF ��ɾ� �Է½� �ߺ���� ����
		}
		else if(n == 1)
		{
			if (!app->Info.start_H) // �̵̹������ϰ�� �ѱ�
			{
				app->Info.start_H = time(&currentTime);
				app->Info.state2 = 25; // �⺻������ ��� ����
				app->Info.state1 = -1;
				app->Info.powerflag = 1;
			}
		}
		else if (n == 4)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(������ ���� ������ּ���)\n");
				continue;
			}
			while (1) {
				printf("\n--- ���� �µ� (18��C ~ 35��C) ---\n");
				printf("\n�� ������ �µ��� �Է��ϼ��� : ");
				scanf("%d", &n2);
				myFlush();

				if (n2 >= 18 && n2 <= 35){
					app->Info.state2 = n2;
					break;
				}
				else {
					printf("\n--- �߸��Է��ϼ̽��ϴ� (���ѿµ� ���� Ȯ��) ---\n");
				}
			}
			printf("\n--- Set Temperature %d��C (%s) ---\n",app->Info.state2, app->Info.Mname);
		}
		else if (n == 3)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(������ ���� ������ּ���)\n");
				break;
			}
			while (1) {
				printf("\n==================================================\n");
				printf("\n1 : ����\n2 : �ù�\n3 : ����\n");
				printf("\n0 : Exit\n");
				printf("\n==================================================\n");
				printf("\n�� ������ ��� ���� : ");
				//scanf("%d", &app->Info.state1);
				scanf("%d", &n2);
				myFlush();

				if (n2 == 0) {
					break;
				}

				if (n2 >= 1 && n2 <= 3){
					app->Info.state1 = n2;
					break;
				}
				else {
					printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
				}
			}

			if (app->Info.state1 == 1) {
				printf("\n--- ���� ��� (%s) ---\n", app->Info.Mname);
			}
			else if (app->Info.state1 == 2) {
				printf("\n--- �ù� ��� (%s) ---\n", app->Info.Mname);
			}
			if (app->Info.state1 == 3) {
				printf("\n--- ���� ��� (%s) ---\n", app->Info.Mname);
			}

		}
		else {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
		}
	}
	return NULL;
}
Func_control displayAircon(APP_t* app) {
	
	printf("\n");
	printf("==================================================\n");
	printf("��ǰ�� : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("�Һ� ���·� : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("�������� : ON\n");
		
		printf("���� �µ� : %d\n",app->Info.state2);
		
		if (app->Info.state1 == 1) {
			printf("������ ��� : ����\n");
		}
		else if (app->Info.state1 == 2) {
			printf("������ ��� : �ù�\n");
		}
		else if (app->Info.state1 == 3) {
			printf("������ ��� : ����\n");
		}
		else if (app->Info.state1 == -1) {
			printf("������ ��� : ��ǳ(�����)\n");
		}
		printf("���ð� : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("�������� : OFF\n");
		printf("���ð� : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}

Func_control controlLight(APP_t* app) {

	int n;
	time_t currentTime;

	while (1) {
		displayLight(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n", electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n");
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n�� ON/OFF ���� : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 1)
		{
			if (!app->Info.start_H) // �̵̹������ϰ�� �ѱ�
			{
				printf("\n--- Light ON (%s) ---\n",app->Info.Mname);
				app->Info.start_H = time(&currentTime);
				app->Info.powerflag = 1;
			}
		}
		else if (n == 2)
		{
			if (app->Info.start_H) {
				printf("\n--- Light OFF (%s) ---\n", app->Info.Mname);
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
				app->Info.powerflag = 0;
			}
			app->Info.start_H = 0; // OFF ��ɾ� �Է½� �ߺ���� ����
		}
	}
	return NULL;
}
Func_control displayLight(APP_t* app) {

	printf("\n");
	printf("==================================================\n");
	printf("��ǰ�� : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("�Һ� ���·� : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("�������� : ON\n");
		printf("���ð� : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("�������� : OFF\n");
		printf("���ð� : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}

Func_control controlCooCoo(APP_t* app) {

	int n;
	int n2;

	while (1) {
		displayCooCoo(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n", electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n3 : Select %smode\n",electromachine[app->Info.type]);
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n�� ��� ���� : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 2) {
			app->Info.powerflag = 0;
			app->Info.state1 = -1; // ������ ������
			if (app->Info.start_H) {
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
			}
			app->Info.start_H = 0; // OFF ��ɾ� �Է½� �ߺ���� ����
		}
		else if (n == 1)
		{
			if (!app->Info.start_H) // �̵̹������ϰ�� �ѱ�
			{
				app->Info.start_H = time(&currentTime);
				app->Info.powerflag = 1;
				app->Info.state1 = -1;
			}
		}
		else if (n == 3)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(������ ���� ������ּ���)\n");
				continue;
			}

			while (1) {
				printf("\n==================================================\n");
				printf("\n1 : ���� �簡��\n2 : ���\n3 : ����\n");
				printf("\n0 : Exit\n");
				printf("\n==================================================\n");
				printf("\n�� CooCoo ��� �Է� : ");
				//scanf("%d", &app->Info.state1);
				scanf("%d", &n2);
				myFlush();

				if (n2 == 0) {
					break;
				}

				if (n2 >= 1 && n2 <= 3) {
					app->Info.state1 = n2;
					break;
				}
				else {
					printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
				}
			}

			if (app->Info.state1 == 1) {
				printf("\n--- ���� �簡�� ��� (%s)---\n", app->Info.Mname);
			}
			else if (app->Info.state1 == 2) {
				printf("\n--- ��� ��� (%s)---\n", app->Info.Mname);
			}
			if (app->Info.state1 == 3) {
				printf("\n--- ���� ��� (%s)---\n", app->Info.Mname);
			}
		}
		else {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
		}
	}
	return NULL;
}
Func_control displayCooCoo(APP_t* app) {

	printf("\n");
	printf("==================================================\n");
	printf("��ǰ�� : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("�Һ� ���·� : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("�������� : ON\n");

		if (app->Info.state1 == 1) {
			printf("CooCoo ��� : �����簡��\n");
		}
		else if (app->Info.state1 == 2) {
			printf("CooCoo ��� : ���\n");
		}
		else if (app->Info.state1 == 3) {
			printf("CooCoo ��� : ����\n");
		}
		else if (app->Info.state1 == -1) {
			printf("CooCoo ��� : �����\n");
		}
		printf("���ð� : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("�������� : OFF\n");
		printf("���ð� : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}

Func_control controlWash(APP_t* app) {
	int n;
	int n2;

	while (1) {
		displayWash(app);
		printf("\n==================================================\n");
		printf("===== %s Control menu =====\n",electromachine[app->Info.type]);
		printf("\n1 : ON\n2 : OFF\n3 : Select %smode\n", electromachine[app->Info.type]);
		printf("\n0 : Exit\n");
		printf("\n==================================================\n");
		printf("\n�� ��� ���� : ");
		scanf("%d", &n);
		myFlush();

		if (n == 0) {
			break;
		}

		if (n == 2) {
			app->Info.powerflag = 0;
			app->Info.state1 = -1; // ������ ������
			if (app->Info.start_H) {
				app->Info.use_H += time(&currentTime) - app->Info.start_H;
			}
			app->Info.start_H = 0; // OFF ��ɾ� �Է½� �ߺ���� ����
			//break;
		}
		else if (n == 1)
		{
			if (!app->Info.start_H) // �̵̹������ϰ�� �ѱ�
			{
				app->Info.start_H = time(&currentTime);
				app->Info.powerflag = 1;
				app->Info.state1 = -1;
			}
			//break;
		}
		else if (n == 3)
		{
			if (app->Info.powerflag == 0) {
				printf("\n--- POWER OFF --- \n(������ ���� ������ּ���)\n");
				break;
			}

			while (1) {
				printf("\n==================================================\n");
				printf("\n1 : �Ϲݼ�Ź\n2 : ������Ź\n3 : ����\n");
				printf("\n0 : Exit\n");
				printf("\n==================================================\n");
				printf("\n�� Wash ��� ���� : ");
				//scanf("%d", &app->Info.state1);
				scanf("%d", &n2);
				myFlush();

				if (n2 == 0) {
					break;
				}

				if (n2 >= 1 && n2 <= 3) {
					app->Info.state1 = n2;
					break;
				}
				else {
					printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
				}
			}

			if (app->Info.state1 == 1) {
				printf("\n--- �Ϲݼ�Ź ��� (%s)---\n", app->Info.Mname);
			}
			else if (app->Info.state1 == 2) {
				printf("\n--- ������Ź ��� (%s)---\n", app->Info.Mname);
			}
			if (app->Info.state1 == 3) {
				printf("\n--- ���� ��� (%s)---\n", app->Info.Mname);
			}

			//break;
		}
		else {
			printf("\n--- �߸��Է��ϼ̽��ϴ� (��Ͽ��� ��ȣ ����) ---\n");
		}
	}
	return NULL;
}
Func_control displayWash(APP_t* app) {

	printf("\n");
	printf("==================================================\n");
	printf("��ǰ�� : %s (%s)\n", app->Info.Mname, electromachine[app->Info.type]);
	printf("�Һ� ���·� : %d\n", app->Info.powerconsumtion);

	if (app->Info.powerflag == 1) {
		printf("�������� : ON\n");

		if (app->Info.state1 == 1) {
			printf("Wash ��� : �Ϲݼ�Ź\n");
		}
		else if (app->Info.state1 == 2) {
			printf("Wash ��� : ������Ź\n");
		}
		else if (app->Info.state1 == 3) {
			printf("Wash ��� : ����\n");
		}
		else if (app->Info.state1 == -1) {
			printf("Wash ��� : �����\n");
		}
		printf("���ð� : %lld\n", time(&currentTime) - app->Info.start_H);
	}
	else {
		printf("�������� : OFF\n");
		printf("�� ���ð� : %lld\n", app->Info.use_H);
	}
	printf("==================================================\n");

	return NULL;
}


