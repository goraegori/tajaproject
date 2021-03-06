void positionT(){
	srand(time(NULL)); //시드 초기화
	int rancap = rand() % 2, randomchar=rand() % (((25 - 0) + 1) + 0); /*아스키코드, a~z, A~Z 중 랜덤*/
	int answerchar=(rancap ? 97:65)+randomchar; //답안 설정
	int userinput=0,testcase=20,cnt=1,wrong=0; //변수 선언 및 초기화, userinput->사용자입력 아스키코드로, testcase->문제수, cnt->시도횟수, wrong->틀린횟수
	while(testcase>0){
		//system("clear");
		system("cls"); //cygwin에서 clear()로 수정 cls는 윈도우용 화면지우기
		printf("---------\n|        |\n|   %c   |\n|        |\n---------\n",answerchar); //답안을 보여줌
		printf("%d번째 입력\n",cnt);
		printf("진행율 : %d%%\n오타수 : %d\n정확도 : %d%%\n입력:",(int)((double)(20-testcase)/(double)20*(double)100),wrong,100-(int)((double)wrong/(double)cnt*(double)100));
		userinput=getch(); //getch() -> 입력을 Enter 키 없이 바로 한글자씩 받음.
		if (userinput==answerchar){ //답안이 맞을 시 이하 실행
			testcase--; //문제수 1개 감소
			cnt++; //시도 횟수 증가
			rancap = rand() % 2; //답안 설정(대문자, 소문자 결정)
			randomchar=rand() % (((25 - 0) + 1) + 0); //답안 설정(문자 결정)
			answerchar=(rancap ? 97:65)+randomchar; //답안 설정
			userinput=0; //사용자 입력 초기화
		}
		else if(userinput==27){ //Esc 입력시 이하 실행
		system("cls");
		main(); //메인 함수(선택장면)으로 돌아감
		}
		else{
			wrong++; //틀린 횟수 증가
			cnt++; //시도 횟수 증가
		}
	}
	// 이하는 진행도가 100%가 되었을 시 실행 (끝)
	//system("clear");
	system("cls");
	printf("오타수 : %d\n정확도 : %d%%\n",wrong,100-(int)((double)wrong/(double)cnt*(double)100)); //오타수 정확도 표시
	printf("Enter를 누르면 돌아갑니다");
	while(1){ //enter 누를때까지 화면이 바뀌지 않음
		userinput=getch(); //사용자 입력 받음
		if(userinput==13){ //입력이 Enter 키 일시
			//system("clear");
			system("cls");
			main(); //메인함수로 돌아감
		}
	}
}
