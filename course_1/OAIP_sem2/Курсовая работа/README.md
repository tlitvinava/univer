# Разработка автоматизации учёта занятости аудиторий в ВУЗе

Реализация программы, работающей с сервером и API при помощи HTTP-запросов.

## Алгоритм отправки HTTP-запроса на сервер (используется в [apimanager.cpp](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/blob/dll/353504/Левшуков%20Д.%20А./Курсовая%20работа/world.cpp) в методе void ApiManager::connect_groups() и void ApiManager::connect_group_schedule(). Применяется там же.
![Схемы1-2](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/assets/143852496/d6531de2-8c02-4318-b17c-264063f309da)


## Алгоритм парсинга (используется в [apimanager.cpp](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/blob/dll/353504/Левшуков%20Д.%20А./Курсовая%20работа/block.cpp) в методе void ApiManager::processJsonGroup(const QString& jsonStr), void ApiManager::processGroupSchedule(const QString& jsonStr) и void ApiManager::processDayObject(const QJsonObject& dayObject, const QString& day).
![Схемы1-3](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/assets/143852496/32d2f97d-20bb-4f39-922f-6568288f587e)


## Алгоритм создания финальной карты (используется в [apimanager.cpp](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/blob/dll/353504/Левшуков%20Д.%20А./Курсовая%20работа/city.cpp) в методе void ApiManager::createFinalSchedule(). Применяется там же.
![Схемы1-4](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/assets/143852496/321e817d-aeec-4295-a706-294339675827)


## Алгоритм поиска занятости аудиторий (используется в [apimanager.cpp](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/blob/dll/353504/Левшуков%20Д.%20А./Курсовая%20работа/world.cpp) в методе QString ApiManager::findScheduleTime(const QMap<QString, QSet<QString>>& finalSchedule, const QString& auditorium, const QDate& date). Применяется там же.
![Схемы1-5](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/assets/143852496/a8cc4639-f050-4a23-881c-763c8e1d7278)


## Алгоритм поиска свободности аудиторий (используется в [apimanager.cpp](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/blob/dll/353504/Левшуков%20Д.%20А./Курсовая%20работа/world.cpp) в методе QStringList ApiManager::findFreeTimeSlots(const QMap<QString, QSet<QString>>& finalSchedule, const QString& auditorium, const QDate& date). Применяется там же.
![Схемы1-6](https://github.com/Dzmitry-Leushukou/Fundamentals-of-algorithmization-and-programming/assets/143852496/49664d95-ca70-409e-ae77-21c82e540c13)

