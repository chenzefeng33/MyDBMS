#pragma once

//������

#include <string>
#include <regex>

using namespace std;

//���ݿ�����׶�
const static regex DB_REGEX("^(create\\sdatabase|drop\\sdatabase|use)\\s(.*?)$", regex_constants::icase);
//create database test

const static string DB_CREATE = "create database";
const static string DB_DROP = "drop database";
const static string DB_USE = "use";

