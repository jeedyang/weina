#pragma once
#include <QString>

enum UserType
{
	general,
	admin,
	superAdmin
};

typedef struct _UserInfo
{
	QString userName;
	UserType type;
	QString password;
}UserInfo;

