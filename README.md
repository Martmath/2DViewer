Just an example of my coding style. I tried to work without c++ templates :).

Software features:
Functional called via buttons:
  Square Create is to create a square. Click the button. Choose a location in your workspace. Press the left mouse button.
  Delete selected is the deletion of the selected items. Select items. Click the button. Items must be removed.
  Set new L / D in selected figure this sets the new size of the selected elements. Select items. Enter the new size in the "L Square (D Circle)" field.
  Click the button. Items should be rendered at their new size.
  Circle Create is to create a circle. Click the button and select a location on the workspace. Press the left mouse button.
  Selected to up is to place the selected items above the rest in the workspace
  Cancel is the exit from the program.

Fields:
  L Square (D Circle) is the size of the element to be specified. X and Y are the position of the mouse.

Actions inside the workspace:
  Selection of elements. Hover your mouse over the item. Hold Ctrl. Click the left mouse button. The item should be highlighted. Release Ctrl.
  Move selected items. highlight the items. Hold down the left mouse button anywhere on the screen. Move the cursor to a new position along with the elements.
  Release the left mouse button.
  Resize an individual element. Move the cursor over the border of the element. Hold down the left mouse button. Move the cursor to a new position and the border of the element should change. Release the left mouse button.
  Moving a single element. Move the mouse inside the element. Hold shift. Hold down the left mouse button.
  Move the cursor to a new position along with the element. Release the left mouse button. Release shift.

The main objects of the code:
View:
Must implement the IViewer interface.
It is based on MFC. A type that implements the ViewerHelper interface is added to the ancestors of the dialog.
This type separates the generated user interface MFC or other, from the piece interacting with the model.
Model:
It must implement the IModel interface, it is implemented using the Model type.
The model is notified by the view through the updateMousePlace method of the model.
The reverse output of data to the user interface occurs
  1) By calling std::function notifyView of the model, which outputs information about the coordinates. It must be previously initialized by the corresponding method from the view.
  2) The controller is responsible for the output to the graphic part. The controller is abstracted (does not know about) both the view that initializes it and the model calling it methods.
Thus, the model is abstracted (not aware of) the view. The reverse output goes through the above controller and notifyView methods.
The schema is NOT classic MVC. Essentially, the classic MVC controller is merged into the model.
The realized controller is implemented from model to view.
The model also works with objects that implement the general IFigure interface. These are the Circle and Square types.

This has been tested on VS16.3.6 x64 environment. The mfc module in the latest VS versions is installed as a separate module.

Possible combinations of test and main application settings:
app: / MDd + Use MFC in a Shared DLL
test: / MDd + Use Standard Windows Libraries

app: / MTd + Use MFC in a Static Library
test: / MTd + Use Standard Windows Libraries
In Additional dependencies add:
$ (SolutionDir) $ (SolutionName) \ $ (IntDir) Square.obj; $ (SolutionDir) $ (SolutionName) \ $ (IntDir) pch.obj;

Просто пример моего стиля. Старался работать без сишных темплейтов :).

Возможности ПО:

Функционал вызываемый через кнопки:
	Square Create - Создание квадрата. Нажмите кнопку, выберите место на рабочем пространстве, нажмите левую кнопку мыши
	Delete selected -Удаление выделенных элементов. Выберите элементы. Нажмите кнопку. Элементы должны быть удалены
	Set new L/D in selected figure -Установка нового размера выделенных элементов. Выберите элементы.Введите новый размер в поле "L Square(D Circle)". 
	Нажмите кнопку. Элементы должны отобразиться с новым размером.
	Circle Create - Создание круга. Нажмите кнопку, выберите место на рабочем пространстве, нажмите левую кнопку мыши
	Selected to up - поместить выделенные элементы выше остальных в рабочем пространстве
	Cancel - выход из программы.

Поля:
	L Square(D Circle) - задаваемый размер элемента. X и Y - положение мыши.

Действия внутри рабочего пространства:
	Выделение элементов: Наведите мышь на элемент. Зажмите Ctrl. Кликните левую кнопку мыши. Элемент должен быть выделен. Отпустите Ctrl.
	Перемещение выделенных элементов - выделите элементы. Зажмите левую кнопку мыши в любом месте экрана. Переместите курсор на новое положение вместе с элементами. 
		Отожмите левую кнопку мыши.
	Изменение размера отдельного элемента - Наведите курсор на границу элемента. Зажмите левую кнопку мыши. Переместите курсор на новое положение - 
		граница элемента при этом должна измениться. Отожмите левую кнопку мыши.
	Перемещение отдельного элемента. Наведите мышь внутрь элемента. Зажмите shift. Зажмите левую кнопку мыши. 
		Переместите курсор на новое положение вместе с элементом. Отпустите левую кнопку мыши. Отпустите shift.

Основные обьекты кода:
Вид:
Должен реализовать IViewer интерфейс.
Основан на MFC - к диалогу, в предки добавляется реализующий вышеуказанный интерфейс ViewerHelper тип.
Даный тип отделяет сгенерированный автоматом пользовательский интерфейс, от части взаимодействующей с моделью.
Модель:
Должна реализовать IModel интерфейс, реализуется типом Model.
Нотификация модели видом происходит через метод updateMousePlace модели.
Обратный вывод данных на пользовательский интерфейс происходит 
	1)вызовом std::function notifyView модели(выводящем информацию о координатах/в дальнейшем - прочую информацию) - 
	которая, должна быть, предварительно инициализирована соответсвующим методом из вида.
	2)Контроллером отвечающим за вывод на графическую часть. Контроллер абстрагирован(не знает об) как от инициализируеющего его вида, 
так и от вызывающей его методы модели.
Таким образом модель абстрагирована (не знает об) виде. Обратный вывод идет через указанные выше методы контроллера и notifyView.
Схема НЕ является классической MVC. По сути классический контроллер(из MVC) обьединен с моделью. 
А реализованный "контроллер" стоит с "обратной" стороны - от модели к виду. 
Модель также работает с обьектами реализующими общий интерфейс IFigure: типы Circle и Square.

Проверено на окружении VS16.3.6 x64, mfc в последних версиях VS ставится отдельным модулем.

Возможные сочетания настроек теста и основного приложения:
приложение:/MDd + Use MFC in a Shared DLL
тест: /MDd + Use Standard Windows Libraries

приложение:/MTd + Use MFC in a Static Library
тест: /MTd + Use Standard Windows Libraries
В Additional dependencies добавить:
$(SolutionDir)$(SolutionName)\$(IntDir)Square.obj;$(SolutionDir)$(SolutionName)\$(IntDir)pch.obj; 
