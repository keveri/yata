open Item; /* get the item type definition */

type state = {
  items: list(Item.item)
};

type action =
  | AddItem(string)
  | ToggleItem(int);

let component = ReasonReact.reducerComponent("Content");

let lastId = ref(0);
let newItem = (text) => {
  lastId := lastId^ + 1;
  {id: lastId^, title: text, completed: false}
};


let contentPageStyle = ReactDOMRe.Style.make(
  ~textAlign="center",
  ~display="inline-block",
  ~marginTop="1em",
  ~width="100%",
  ()
);

let itemListStyle = ReactDOMRe.Style.make(
  ~textAlign="center",
  ~display="inline-block",
  ~marginTop="1em",
  ~width="100%",
  ()
);

let make = _children => {
  ...component,
  initialState: () => {
    items: [{
      id: 0,
      title: "Do this thing",
      completed: false
    }]
  },
  reducer: (action, {items}) =>
    switch(action) {
      | AddItem(text) =>
        ReasonReact.Update({items: [newItem(text), ...items]})
      | ToggleItem(id) =>
        let items = List.map(
          (item) =>
            item.id === id ?
              {...item, completed: ! item.completed} : item,
          items
        );
        ReasonReact.Update({items: items})
    },
  render: ({state: {items}, reduce}) => {
    let nItems = List.length(items);
    <div>
      <MaterialUI.Paper style=contentPageStyle>
        <Input onSubmit=(reduce((text) => AddItem(text))) />
        <MaterialUI.Paper style=itemListStyle>
          <div className="count">
            (Helpers.str(string_of_int(nItems) ++ " thing(s) todo"))
          </div>
          <MaterialUI.Divider/>
          <div className="items">
            (
              List.map((item) =>
                <Item
                  key=(string_of_int(item.id))
                  onToggle=(reduce(() => ToggleItem(item.id)))
                  item
                />,
                items
              )
              |> Array.of_list
              |> ReasonReact.arrayToElement
            )
          </div>
        </MaterialUI.Paper>
      </MaterialUI.Paper>
    </div>
  }
};
