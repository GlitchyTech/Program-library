#include <iostream>
#include <vector>
#include <cstdlib>

/* Изначально пандорианцы обладают некоторым запасом золота. Они решили в один из дней года купить на все это золото воды, а в какой-то последующий день продать всю купленную воду и получить прибыль за счет разницы стоимости. Конечно же, пандорианцы хотят максимизировать свой доход в результате этих махинаций. Помогите им выбрать оптимальные дни для покупки и продажи воды!
Входные данные
В первой строке задано целое число N (2 ≤ N ≤ 1000) — количество дней в году на планете Арракис.
Во второй строке заданы N целых положительных чисел a i ( 1 ≤ i ≤ N , 1 ≤ a i ≤ 5000), задающих стоимость воды на Арракисе в день i .
Выходные данные
Выведите два целых числа: первое число — номер дня, в который стоит купить воду, второе число — номер дня, в который следует воду продать. Дни нумеруются с единицы. Если оптимальных пар дней для покупки/продажи несколько, то выведите любую из них.
Выведите два нуля, если покупка и продажа воды по указанной схеме не принесет пандорианцам прибыли.
Примеры
Входные данные 	            Выходные данные
6   10 3 5 3 11 9           2 5
4   5 5 5 5	                0 0
*/

using namespace std;

int main()
{
    int n, dif, count = 0;
    cin >> n;
    vector <int> b(n);
    vector <int> r;
    vector <int> v;
    // Чтение
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    //Проверка массива на содержание всех одинаковых элементов
    for (int i = 0; i < n - 1; i++){
        if (b[i] == b[i + 1]){
            count++;
        }
    }
    if (count == n - 1){
        cout << 0 << " " << 0;
        exit(0);
    }
    //Сохранение разности между элементами и их индексы
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            dif = b[i] - b[j];
            r.push_back(dif);
            v.push_back(i);
            v.push_back(j);
        }
    }
    //Нахождение наименьшей разности
    int num_min = r[0], index = 0;
    for (unsigned i = 0; i < r.size(); i++){
        if (num_min > r[i]){
            num_min = r[i];
            index = i;
        }
    }
    //Прибавление 1 из - за того, что отсчёт с 1 в задаче
    cout << v[index * 2] + 1 << " " << v[index * 2 + 1] + 1;
    return 0;
}