type state = string;

/* ReasonReact's bindings don't yet have a well-typed way to get the value of
 * an input element */
let valueFromEvent = (evt) : string => (
  evt
  |> ReactEventRe.Form.target
  |> ReactDOMRe.domElementToObj
)##value;


let component = ReasonReact.reducerComponent("Input");

let make = (~onSubmit, _children) => {
  ...component,
  initialState: () => "",
  reducer: (newText, _text) => ReasonReact.Update(newText),
  render: ({state: text, reduce}) =>
    <div>
      <MaterialUI.Input
        value=text
        inputType="text"
        placeholder="What to do?"
        onChange=(reduce((evt) => valueFromEvent(evt)))
      />
      <MaterialUI.Button
        onClick=(
          (_evt) => {
            onSubmit(text);
            (reduce(() => ""))()
          }
        )
      >
        (Helpers.str("Add item"))
      </MaterialUI.Button>
    </div>
};
