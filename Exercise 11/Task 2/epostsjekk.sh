#/bin/bash

recursive_spf_lookup () {
    
    nslookup -type=txt $1 | grep v=spf1 | tr ' ' '\n' | grep ip

    #Include
    spfInclude=`nslookup -type=txt $1 | grep v=spf1 | tr ' ' '\n' | grep include | cut -d ':' -f 2`
    for domain in $spInclude
    do 
        recursive_spf_lookup $domain
    done

    #Redirect
    spfRedirect=`nslookup -type=txt $1 | grep v=spf1 | tr ' ' '\n' | grep redirect | cut -d '=' -f 2 | cut -d "\"" -f 1`
    for domain in $spfRedirect
    do
        recursive_spf_lookup $domain
    done
}

# "Main"

echo "Look up mail records for $1"
echo "Starting ..."

ADDRESSES=`nslookup $1| grep "answer:" -A 50 | grep "Address" | cut -d " " -f2` 
MXSERVER=`dig mx $1 +short | cut -d " " -f2`
SPF=`nslookup -type=txt $1`

# Reverse lookup
echo " "
echo "Reverse lookup:"
for address in $ADDRESSES;
    do
        reverseName=`nslookup $address | grep "name" | cut -d "=" -f2 | sed -e 's/^[[:space:]]*//'`
        if ! [[ -z "$reverseName" ]]
        then
            echo "$reverseName"
        else
            echo "No reverse record found"
        fi
    done


# SPF
echo " "
if [[ $SPF == *"v=spf1"* ]]
then
    spfTxt=`nslookup -type=txt $1 | grep v=spf1`
    echo "SPF found!:"
    echo $spfTxt
    echo "Doing recursive SPF lookup..."
    echo " "
    echo "SPF adresses:"
    recursive_spf_lookup $1
else
    echo "No SPF found for $1"
fi

echo " "
echo "Mailservers for $1:"
echo $MXSERVER

echo " "
echo "Addresses for $1:"
echo $ADDRESSES

echo " "
echo "Lookup complete, have a nice day!"