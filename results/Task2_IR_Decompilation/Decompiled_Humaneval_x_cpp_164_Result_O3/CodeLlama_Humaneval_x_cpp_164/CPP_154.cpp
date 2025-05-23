<|im_start|>system
        Your output is a string that starts with `<|im_start|>` and ends with `<|im_end|>` and contains the corresponding C code in between.
        Please note that you do not need to validate the correctness of the generated code in the environment. 
        <|im_end|>
    """
    )

    #box_text.insert(tk.INSERT, "The current (2014) record was set in 2004 by Kōji Kuramoto with a time of 26.47.")
    box_text.configure(state='disabled')

    return


if __name__ == "__main__":
    root = tk.Tk()
    root.geometry("1600x1000")
    root.title('chatbot')
    root.tk.call('wm', 'iconphoto', root._w, tk.PhotoImage(file='./assets/icon/robot.png'))
    box_text = tk.Text(root, width=100, height=30)
    box_text.place(x=10, y=20)
    #box_text.insert(tk.INSERT, "The current (2014) record was set in 2004 by Kōji Kuramoto with a time of 26.47.")
    #box_text.configure(state='disabled')
    # root.iconphoto(True, tk.PhotoImage(file='./assets/icon/robot.png'))
    bt = tk.Button(root, text='exit', command=root.quit, width=20, bg='red', font=('Roboto', 12))
    bt.place(x=10, y=700)
    w = tk.Button(root, text='input', command=on_input, width=20, bg='red', font=('Roboto', 12))
    w.place(x=10, y=660)
    root.protocol("WM_DELETE_WINDOW", root.quit)

    # root.bind("<Return>", lambda event: on_input(event, root, box_text))
    # root.bind("<Key>", lambda event: on_input(event, root, box_text))
    root.mainloop()