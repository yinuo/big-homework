#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

int ret = 0, empty = 1, id, age;
char *sql = NULL, *err = 0;
char name[20] = { 0 };
char gender[7] = { 0 };

sqlite3 *db;

void empty_cache()
{
	char ch;
	ch = getchar();
	while (ch != EOF && ch != '\n') {
		ch = getchar();
	}
}

int rscallback(void *p, int argc, char **argv, char **argvv)
{

	int i;
	*(int *) p = 0;
	for (i = 0; i < argc; i++) {
		printf("%s = %s ", argvv[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, const char *argv[])
{
	ret = sqlite3_open("./test.db", &db);
	if (ret != SQLITE_OK) {
		fputs(sqlite3_errmsg(db), stderr);
		fputs("\n", stderr);
		exit(1);
	}
	//sql =
	 //   sqlite3_mprintf
	//    ("create table student(id integer primary key,name text,gender text,age integer);");
	//ret = sqlite3_exec(db, sql, 0, 0, &err);
	while (1) {
		printf("1.Display all records\n");
		printf("2.Insert Record\n");
		printf("3.Delete Record\n");
		printf("4.Exit\n");
		printf("Please Select[1-4]:");
		int i;
		scanf("%d", &i);
		switch (i) {
		case 1:
			xianshi();
            empty_cache();
			break;
		case 2:
			charu();
            empty_cache();
			break;
		case 3:
			shanchu();
         	empty_cache();
			break;
		case 4:
			exit(0);
			break;
		default:
            empty_cache();
			break;
		}
	}
	if (ret != SQLITE_OK) {
		fputs(err, stderr);
		fputs("\n", stderr);
		sqlite3_close(db);
		exit(1);
	}
	sqlite3_close(db);
	return 0;
}

xianshi()
{
	sql = sqlite3_mprintf("select * from student;");
	ret = sqlite3_exec(db, sql, rscallback, &empty, &err);
	sqlite3_free(sql);
	if (empty) {
		fputs("table student is empty\n", stderr);
                	sql =
	    sqlite3_mprintf
	    ("create table student(id integer primary key,name text,gender text,age integer);");
	ret = sqlite3_exec(db, sql, 0, 0, &err);
		exit(1);
	}
}

charu()
{
    start:printf("Please input id name gender age:");
    empty_cache();
	scanf("%d %20s %s %d", &id, name, gender, &age);
	if ((id > 0 && id < 1000) && (age > 0 && age < 100) && ((strcmp(gender, "female") == 0
    || strcmp(gender, "male") == 0))) {
		sql =
		    sqlite3_mprintf
		    ("insert into student values(%d,%Q,%Q,%d);", id, name,
		     gender, age);
		ret = sqlite3_exec(db, sql, 0, 0, &err);
		sqlite3_free(sql);
	} else {
//		empty_cache();
		goto start;
	}
}

shanchu()
{
	printf("1.Delete by id\n");
	printf("2.Delete by name\n");
	printf("Your choice:");
    empty_cache();
	int a;
	scanf("%d", &a);
	switch (a) {
	case 1:
		printf("Please input the id:");
		scanf("%d", &id);
		sql =
		    sqlite3_mprintf("delete from student where id = %d;",
				    id);
		ret = sqlite3_exec(db, sql, 0, 0, &err);
		sqlite3_free(sql);
		break;
	case 2:
		printf("Please input the name:");
		scanf("%s", name);
		sql =
		    sqlite3_mprintf
		    ("delete from student where name = %Q;", name);
		ret = sqlite3_exec(db, sql, 0, 0, &err);
		sqlite3_free(sql);
		break;
	default:
		exit(0);

	}

}
