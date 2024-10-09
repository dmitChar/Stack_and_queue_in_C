# Stack_and_queue_in_C
## Суть программы
- Вывод на экран состояния моделируемой системы на каждой итерации работы (содержимое стека(ов), очереди(ей), процессора(ов))
- Для каждой задачи из списка входных задач должно быть определено время поступления;
- Наличие, как автоматического генератора задач, так и возможность ручного добавления задач, с указанием их параметров (в зависимости от задания);
- Обработка ситуаций, при которых какая-либо структура данных может быть переполнена.
## О работе программы
Система состоит из процессора P, трѐх очередей F0, F1, F2 и стека S. В систему поступают запросы на выполнение задач.
![image](https://github.com/user-attachments/assets/2ee63669-4d94-4114-bff1-efccb36d313e)
Поступающие запросы ставятся в соответствующие приоритетам очереди. Сначала обрабатываются задачи из очереди F0. Если она пуста, можно обрабатывать задачи из очереди F1. 
Если и она пуста, то можно обрабатывать задачи из очереди F2. Если все очереди пусты, то система находится в ожидании поступающих задач (процессор свободен), либо в режиме обработки предыдущей задачи (процессор занят). 
Если поступает задача с более высоким приоритетом, чем обрабатываемая в данный момент, то обрабатываемая помещается в стек, если она выполнена менее чем на половину по времени, и может обрабатываться тогда и только тогда, когда все задачи с более высоким приоритетом уже обработаны.

## Пример работы программы
![image](https://github.com/user-attachments/assets/b396b3f5-c1ca-4a87-ac28-7cb799d08803)
![image](https://github.com/user-attachments/assets/45174baa-985f-4ca4-bff1-8baa8eb0aafb)
![image](https://github.com/user-attachments/assets/445314a6-c96b-473c-b6e3-9608316ed0ae)
![image](https://github.com/user-attachments/assets/01f34c08-cea4-4ebc-99ab-96bb02d118a4)
![image](https://github.com/user-attachments/assets/15438cf5-14e6-4d1f-be74-a3cda394a653)
