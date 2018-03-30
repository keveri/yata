type state = {
  items: list(Item.item)
};

type action =
  | AddItem;

let component = ReasonReact.reducerComponent("Content");

let newItem = () : Item.item => {title: "New item", completed: false};


let contentPageStyle = ReactDOMRe.Style.make(
  ~textAlign="center",
  ~display="inline-block",
  ~marginTop="1em",
  ~width="100%",
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
        (Helpers.str("Add new todo"))
      </MaterialUI.Button>
      <MaterialUI.Paper style=contentPageStyle>
        <div className="count">
          (Helpers.str(string_of_int(nItems) ++ " thing(s) todo"))
        </div>
        <div className="items">
          (
            List.map((item) => <Item item/>, items)
            |> Array.of_list
            |> ReasonReact.arrayToElement
          )
        </div>
      </MaterialUI.Paper>
    </div>
  }
};
