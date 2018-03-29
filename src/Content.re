type item = {
  title: string,
  completed: bool
};

type state = {
  items: list(item)
};

let component = ReasonReact.reducerComponent("Content");

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
  reducer: ((), _) => ReasonReact.NoUpdate,
  render: ({state: {items}}) => {
    let nItems = List.length(items);
    <MaterialUI.Paper style=contentPageStyle>
      (str(string_of_int(nItems) ++ " thing(s) todo"))
    </MaterialUI.Paper>
  }
};
