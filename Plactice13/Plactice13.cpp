// Plactice13.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。


#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

#define ANSWER_MAX 100
#define ANSWER_MIN 0
#define TRUE 1
#define FALSE 0
#define MAXIMUM_NUMBER_OF_DIGITS_SELECT_NUMBER 3
#define MAXIMUM_NUMBER_OF_DIGITS_RETRY_NUMBER 1
#define NULL_AND_ENTER 2 


int create_answer_number(int max, int min) {
    int answer_point;
    srand(time(NULL));
    answer_point = (rand() % max) + min;
    return answer_point;
}

void string_clear(char str[],int string_size) {
    for (int i = 0; i < string_size; i++) {
        str[i] = '\0';
    }
}

int is_int_number_within_range(int int_number, int max, int min) {
    if ((int_number < min) || (int_number > max)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

int input_int_number(char input_number[],int string_size,int max,int min) {
    char buff_clear;
    int is_int_number = TRUE;
    int is_number_within_range = FALSE;
    int int_number;
    do {
        do {
            printf("%d～%dの整数を入力してください : ", min, max);
            fgets(input_number, string_size, stdin);
            if ((strchr(input_number, '\n')) == NULL) {
                puts("入力桁数が多すぎます！");
                do {
                    buff_clear = getchar();
                } while (buff_clear != '\n');
            }
            else {
                for (int i = 0; i < string_size; i++) {
                    if (!isdigit(input_number[i])) {
                        if (input_number[i] != NULL && input_number[i] != '\n') {
                            is_int_number = FALSE;
                            break;
                        }
                    }
                    else {
                        is_int_number = TRUE;
                    }
                }
                if (is_int_number == TRUE) {
                    if (input_number[0] != '0') {
                        int_number = atoi(input_number);
                        is_number_within_range = is_int_number_within_range(int_number, max, min);
                    }
                    else {
                        if (input_number[1] == '\n') {
                            int_number = atoi(input_number);
                            is_number_within_range = is_int_number_within_range(int_number, max, min);
                        }
                    }
                }
                else {
                    puts("整数以外を入力しないでください");
                }
            }
        } while (is_int_number == FALSE);
    } while (is_number_within_range == FALSE);
    return int_number;
}

int main()
{
    char input_select_number[MAXIMUM_NUMBER_OF_DIGITS_SELECT_NUMBER + NULL_AND_ENTER];
    char input_retry_result[MAXIMUM_NUMBER_OF_DIGITS_RETRY_NUMBER + NULL_AND_ENTER];
    int select_number;
    int play_count = 0; 
    int answer_number;
    int retry = TRUE;
    int is_int_number = TRUE;
    int char_size_select_number;
    int char_size_retry_result;
    char_size_select_number = (sizeof input_select_number);
    char_size_retry_result = (sizeof input_retry_result);
    answer_number = create_answer_number(ANSWER_MAX, ANSWER_MIN);
    string_clear(input_select_number,char_size_select_number);
    string_clear(input_retry_result,char_size_retry_result);

    puts("数当てゲームを行います。");
    printf("PCが決めた%d～%dの任意の値を当ててみてください\n",ANSWER_MIN,ANSWER_MAX);
    puts("PCの値より小さければ「Small」と大きければ「Big」と、そして見事同じ値なら「Bingo!」と表示されます。");
    puts("当たるまで何回でも挑戦できます。");
    puts("それでは数当てゲームスタート！！");

    while(retry == TRUE) {
        play_count++;
        select_number = input_int_number(input_select_number, char_size_select_number, ANSWER_MAX, ANSWER_MIN);
        if (select_number > answer_number) {
            puts("Big");
        }
        if (select_number < answer_number) {
            puts("Small");
        }
        if (select_number == answer_number) {
            puts("Bingo!");
            printf("今回当たるまでにかかった回数は%dです\n", play_count);
            puts("もう一度遊びますか？　1...はい　0...いいえ");
            retry = input_int_number(input_retry_result, char_size_retry_result, TRUE, FALSE);
            if (retry == TRUE) {
                play_count = 0;
                answer_number = create_answer_number(ANSWER_MAX, ANSWER_MIN);
            }
        }
    }
    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
