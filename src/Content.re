type item = {
  title: string,
  completed: bool
};

type state = {
  items: list(item)
};

type action =
  | AddItem;

let component = ReasonReact.reducerComponent("Content");

let newItem = () => {title: "New item", completed: false};

let str = ReasonReact.stringToElement;


let contentPageStyle = ReactDOMRe.Style.make(
  ~textAlign="center",
  ~display="inline-block",
  ~marginTop="1em",
  ~width="100%",
  ~height="4em",
  ()
);

let make = _children => {
  ...component,
  initialState: () => {
    items: [
      {title: "Do this thing", completed: false}
    ]
  },
  reducer: (action, {items}) =>
    switch(action) {
      | AddItem => ReasonReact.Update({items: [newItem(), ...items]})
    },
  render: ({state: {items}, reduce}) => {
    let nItems = List.length(items);
    <div>
      <MaterialUI.Button onClick=(reduce((_evt) => AddItem))>
        (str("Add new todo"))
      </MaterialUI.Button>
      <MaterialUI.Paper style=contentPageStyle>
        (str(string_of_int(nItems) ++ " thing(s) todo"))
      </MaterialUI.Paper>
    </div>
  }
};
