flood(node, packet)
begin
    assign(node, packet)

    foreach (link in node)
        if (not received(link, packet)) then
            flood(link, packet)
        endif
    loop
end
