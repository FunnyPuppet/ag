#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *word;
    char c;
} WordMap;

bool wordPattern(char* pattern, char* s) {
    // 复制原字符串，因为strtok会修改原字符串
    char *s_copy = strdup(s);
    if (s_copy == NULL) {
        return false; // 内存分配失败
    }

    // 分割字符串s为单词数组
    char *words[300]; // 最多300个单词
    int word_count = 0;
    char *token = strtok(s_copy, " ");
    while (token != NULL && word_count < 300) {
        words[word_count++] = token;
        token = strtok(NULL, " ");
    }

    int pattern_len = strlen(pattern);
    // 检查单词数量是否与pattern长度一致
    if (word_count != pattern_len) {
        free(s_copy);
        return false;
    }

    // 初始化字符到单词的映射数组
    char *char_map[26] = {NULL};
    // 初始化单词到字符的映射数组
    WordMap word_map[300];
    int word_map_size = 0;

    for (int i = 0; i < pattern_len; i++) {
        char c = pattern[i];
        char *word = words[i];

        // 检查当前字符c是否已经有映射的单词
        if (char_map[c - 'a'] != NULL) {
            // 检查映射的单词是否与当前单词一致
            if (strcmp(char_map[c - 'a'], word) != 0) {
                free(s_copy);
                return false;
            }
        } else {
            // 检查当前单词是否已经映射到其他字符
            int found = 0;
            for (int j = 0; j < word_map_size; j++) {
                if (strcmp(word_map[j].word, word) == 0) {
                    found = 1;
                    if (word_map[j].c != c) {
                        free(s_copy);
                        return false;
                    } else {
                        // 单词已正确映射到当前字符，更新char_map
                        char_map[c - 'a'] = word;
                    }
                    break;
                }
            }
            if (!found) {
                // 添加新的映射关系
                char_map[c - 'a'] = word;
                word_map[word_map_size].word = word;
                word_map[word_map_size].c = c;
                word_map_size++;
            }
        }
    }

    free(s_copy);
    return true;
}

// 测试示例
int main() {
    // 示例1
    char pattern1[] = "abba";
    char s1[] = "dog cat cat dog";
    printf("%s\n", wordPattern(pattern1, s1) ? "true" : "false"); // 输出true

    // 示例2
    char pattern2[] = "abba";
    char s2[] = "dog cat cat fish";
    printf("%s\n", wordPattern(pattern2, s2) ? "true" : "false"); // 输出false

    // 示例3
    char pattern3[] = "aaaa";
    char s3[] = "dog cat cat dog";
    printf("%s\n", wordPattern(pattern3, s3) ? "true" : "false"); // 输出false

    return 0;
}