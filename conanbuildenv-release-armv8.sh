echo "echo Restoring environment" > "/Users/anatolii/project/capybara-messenger/deactivate_conanbuildenv-release-armv8.sh"
for v in 
do
    is_defined="true"
    value=$(printenv $v) || is_defined="" || true
    if [ -n "$value" ] || [ -n "$is_defined" ]
    then
        echo export "$v='$value'" >> "/Users/anatolii/project/capybara-messenger/deactivate_conanbuildenv-release-armv8.sh"
    else
        echo unset $v >> "/Users/anatolii/project/capybara-messenger/deactivate_conanbuildenv-release-armv8.sh"
    fi
done

